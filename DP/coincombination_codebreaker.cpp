#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ACed
const int M=13371337;
int main () {
	int n, s; cin >> n >> s;
	vector<int> v(n+1);
	v[0]=0;
	for(int i =1; i<n+1; i++) cin >> v[i];
	vector<vector<ll>> dp(s+1, vector<ll> (n+1, 0));
	dp[0][0]=1;
	for(int i = 0; i<s+1; i++){
		for(int j =1; j<n+1; j++){
			if(i-v[j]>=0) dp[i][j]=(dp[i-v[j]][j]%M+dp[i][j-1]%M)%M;
			else dp[i][j]=dp[i][j-1]%M;
		}
	}
	cout << dp[s][n]%M;
	
}