#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &i: v) cin >> i;
	map<ll, ll> m;
	for(int i =0; i<n; i++) {
		map<ll, ll>::iterator it=m.lower_bound(v[i]);
		if(m.empty()) {
			m[v[i]]=1;
			continue;
		}
		it--;
		
		m[v[i]]=(*it).second+1;
	}
	ll ans =0;
	for(auto i:m) {
		ans = max(ans, i.second);
	}
	cout << ans;
}