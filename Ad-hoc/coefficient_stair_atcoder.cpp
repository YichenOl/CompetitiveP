// Source: https://usaco.guide/general/io
//ACed
#include "../bits/stdc++.h"
using namespace std;
#define yay cout << "here" << endl
#define int long long
int n, k;
vector<vector<int>> v;
void dfs (int s, int d, vector<int> temp, int c) {
	vector<int> vn = temp;
	if(c!=-1) vn.push_back(c);
	if(d == n-1) {
		if((k-s)%(d+1)==0) {
			vn.push_back((k-s)/(d+1));
			v.push_back(vn);
			return;
		} else {
			return;
		}
	}
	
	for (int i = 0; i <= (k-s)/(d+1); i++) {
		// cout << i <<' '<<d<<endl; 
		dfs(s+i*(d+1), d+1, vn, i);
	}
}

int32_t main() {
	cin >> n >> k;
	vector<int> temp = {};
	dfs(0, 0, temp, -1);
	
	for(auto i:v) {
		for(int j:i) cout << j << ' ';
		cout << '\n';
	}
	
}
