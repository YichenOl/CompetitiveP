#include "../bits/stdc++.h"
using namespace std;
#define int long long
typedef long long ll;
//ACed
vector<vector<int>> v;

int32_t main() {
	int tst; cin >> tst;
	while(tst--) {
		int n; cin >> n;
		int t = 0;
		int mi = 1000000000 +10;
		v.assign(n, vector<int> (3));
		for(int i=0; i<n; i++) {
			int a, b; cin >> a >> b;
			v[i][0] = a-b;
			v[i][1] = a;
			v[i][2] = b;
			mi = min(a, mi);
			t+=a;
		}
		sort(v.begin(), v.end(), greater<vector<int>>());
		vector<int> res(n);
		res[0]=t;
		for(int i=0; i<n-1; i++) {
			t -= v[i][0];
			res[i+1] = t;
			if(n-1-i<i+1) {
				res[i+1] += mi*(2*(1+i)-n);
			}
		}
//		for(int i:res) cout << i << ' ';
//		cout << '\n';
		sort(res.begin(), res.end());
		cout << res.front() << '\n';
	}
	
}