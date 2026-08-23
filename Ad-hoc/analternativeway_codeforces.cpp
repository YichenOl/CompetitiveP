#include "../bits/stdc++.h"
#define int long long
//ACed
using namespace std;
int32_t main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(auto &i:a) cin >> i;
		for(auto &i:b) cin >> i;
		int jia = 0;
		bool bo = false;
		for(int i =0; i<n; i++) {
			if(a[i]<b[i]) jia+=(b[i]-a[i]);
			if(a[i]>b[i]) {
				if(jia < a[i]-b[i]) {
					cout << "NO\n";
					bo = true;
					break;
				} else {
					jia -= a[i]-b[i];
				}
			}
		}
		if(bo == false) cout << "YES\n";
		
	}
}