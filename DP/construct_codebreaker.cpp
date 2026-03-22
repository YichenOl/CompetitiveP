#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const ll M = 1e9+7;
int32_t main() {
	int n, m, k;
	cin >> n >> m >>k;
	vector<vector<ll>> v(n, vector<ll>());
	for(int i =0; i<k; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[b].push_back(a);
	}
	
	vector<vector<ll>> dp(m, vector<ll>(n));
	ll prev=n;
	dp[0]=vector<ll> (n, 1);
	for(int i =1; i<m; i++) {
		ll t=0;
		for(int j =0; j<n; j++) {
			dp[i][j]=prev;
			for(ll p:v[j]) {
				dp[i][j]=(dp[i][j]-dp[i-1][p]%M+M)%M;
			}
			t+=dp[i][j]%M;
		}
		prev=t%M;
	}
	
	ll ans =0;
	for(int i =0; i<n; i++) {
		ans = (ans+dp[m-1][i])%M;
	}
	cout << ans;
}