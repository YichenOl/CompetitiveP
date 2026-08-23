#include "../bits/stdc++.h"
#define fi first
#define se second
using namespace std;
typedef long long ll;
//ACed 
bool iss(int n) {
	if (n < 0) return false;
	int m = n & 15;
	if (m != 0 && m != 1 && m != 4 && m != 9)
		return false;
	int r = sqrt(n);
	return r * r == n;
}

void dfs(vector<vector<int>>& v, vector<int>& st, int& x) {
	st[x] = 1;
	
	for(int i:v[x]) {
		if(st[i]!=-1) continue;
		dfs(v, st, i);
		st[x]+=st[i];
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> sq;
		vector<vector<int>> v(n);
		for(int i=0; i<n; i++) {
			int a; cin >> a;
			if(iss(a) == true) sq.push_back(i);
		}

		for(int i=0; i<n-1; i++) {
			int x, y;
			cin >> x >> y;
			v[x-1].push_back(y-1);
			v[y-1].push_back(x-1);
		}
		
		
		long long ans  = 0;
		vector<int> st(n, -1);
		int p = 0;
		dfs(v, st, p);
			
		for(int i:sq) {
			if(v[i].size()<=1) continue;
			vector<int> d;
			for(int j:v[i]) {
				if(st[j]<st[i]) d.push_back(st[j]);
				else d.push_back(st[0]-st[i]);
			}
////			cout << i << '(';
//			for(int j:d) cout << j << ' ';
			ll sum = 0;
			ll c2 = 0;
			ll c3 = 0;
			for(int j:d) {
				c3 += c2*j;
				c2 += sum*j;
				sum += j;
			}
			
			ans += (c2+c3);
//			cout << ")\n";
		}
		
		cout << ans <<'\n';
	}
}