#include "../bits/stdc++.h"
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> v(n+1);
	
	for(int i=0; i<m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	
	queue<pair<int, int>> q;
	q.push({1, 1e9});
	vector<int> f(n+1, -1);
	f[1] = 0;
	
	bool b=0;
	while(!q.empty()) {
		int cur = q.front().first;
		int cc = q.front().second;
		q.pop();
		for(auto i:v[cur]) {
			int city = i.first;
			int col = i.second;
//			cout << cur << ' ' << city << ' ' << col << ' '<< q.front().first<<'\n';
		if(col==cc) continue;
			f[city] = f[cur]+1;
			if(city == n) {
				b=1;
				cout << f[city];
				break;
//				cout << "yay";
			}
			q.push({city, col});
		}
//		cout << '\n';
		if(b==1) break;
	}
	
	if(b==0) cout << -1;
}