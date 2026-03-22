#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ACed
int main() {
	ll n, m; cin >> n >> m;
	vector<ll> k(m);
	for(int i =0; i<m; i++) {
		cin >> k[i];
	}
	sort(k.begin(), k.end());
	ll t=0;
	ll ans =0;
	for(int i =0; i<m; i++) {
		if(t+k[i]>n) break;
		t+=k[i];
		ans+=1;
	}
	cout << ans;
}