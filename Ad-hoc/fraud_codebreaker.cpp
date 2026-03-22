#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second


int main() {
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for(int i=0; i<n; i++) cin >> v[i].first;
	for(int i=0; i<n; i++) cin >> v[i].se;
	
	long double maxi = 1e9, mini = 0;
	for(int i=0; i<n-1; i++) {
		int ai = v[i].fi, bi = v[i].se, aj = v[i+1].fi, bj = v[i+1].se;
		if(bi==bj) {
			if(aj>=ai) {
				cout << "NO";
				return 0;
			}
			else continue;
		}
		int a = bi-bj; int b = aj-ai;
		long double x = (long double)b/(long double)a;
//		cout <<b<<"a>"<<a<<", b</>"<<x<<'\n';
		if(a < 0 && x > 0) {
			maxi = min(maxi, x);
//			cout << "maxi:" << maxi;
		} else if(a > 0) {
			mini = max(mini, x);
//			cout << "mini:" << mini;
		} else {
			cout << "NO";
			return 0;
		} 
	}
	if (mini < maxi) cout << "YES";
	else cout << "NO";
}
