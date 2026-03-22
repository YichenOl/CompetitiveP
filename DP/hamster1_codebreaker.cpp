#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ACed
int main() {
	int n, k; cin >> n >>k;
	vector<vector<ll>> dp(n, vector<ll> (k+1, 0));
	vector<int> v(n);
	for(int i = 0; i<n; i++) {
		cin >> v[i];
	}
	
	for(int i = 0; i<n; i++) {
		ll mini = LLONG_MAX;
		for(int j = 0; j<k; j++) {
			ll t=j+1;
			if(i-t < 0) continue;
			else dp[i][j] = dp[i-t][k]+abs(v[i]-v[i-t]);
			mini = min(mini, dp[i][j]);
		}
		if(mini==LLONG_MAX) dp[i][k]=0;
		else dp[i][k]=mini;
	}
	
	cout << dp[n-1][k];
}