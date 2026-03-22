#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<int> v(n+1);
	vector<vector<int>> map;
	for(int i =1; i <= n; i++) {
		cin >> v[i];
	}
	
	vector<int> dp(n+1, 0);
	for(int i =n; i >0; i--) {
		if(v[i]==i) {
			dp[i]=i;
		} else {
			dp[i]=dp[v[i]];
		}
	}
	
	for(int i =1; i <= n; i++) {
		cout << dp[i]<<' ';
	}
	
}