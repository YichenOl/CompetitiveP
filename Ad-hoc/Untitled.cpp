#include "../bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define int long long
int32_t main() {
	int n, k, tm; cin >> n >> k >> tm;
	int ans =0;
	vector<int> ao(n);
	for(int i=0; i<n; i++) {
		cin >> ao[i];
	}
	
	sort(ao.begin(), ao.end());
	int prev = 0;
	for(int i=0; i<n; i++) {
		if(ao[i]>tm) {
			int g = tm - prev;
			ans += (g+k-1)/k;
			prev = ao[i]+k;
//			cout << prev <<' '<< ans << '\n';
			break;
		}
		if(ao[i]-prev>0) {
			int g = ao[i]-prev;
			ans += (g+k-1)/k;
			prev = ao[i]+k;
//			cout << prev <<' '<< ans << '\n';
		} else {
			prev = ao[i]+k;
//			cout << prev <<' '<< ans << '\n';
		}
	}
	if(prev<tm) {
		int g = tm-prev;
		ans += (g+k-1)/k;
	}

	cout << ans;
}