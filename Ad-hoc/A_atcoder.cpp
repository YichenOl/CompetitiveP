#include "../bits/stdc++.h"
using namespace std;
#define int long long
#define fi first
#define se second
#define fori(x) for(int i=0; i<x; i++)
#define forj(y) for(int j=0; j<y; j++)

int32_t main() {
	int h, w, k; cin >> h >> w >> k;
	vector<bool> grw(h);
	vector<bool> gcl(w);
	vector<vector<char>> grid(h, vector<char>(w));
	vector<vector<vector<pair<int, int>>>> v(h, vector<vector<pair<int, int>>>(w, vector<pair<int, int>>() ) );
	int lh[] = {0, 1, 0, -1};
	int lw[] = {-1, 0, 1, 0};
	fori(h) {
		forj(w) {
			char t; cin >> t;
			grid[i][j] = t;
		}
	}
	
	fori(h) {
		forj(w) {
			char t = grid[i][j];
			if(t == '.') {
				for(int p=0; p<4; p++){
					if(i+lh[p]>=0 && i+lh[p]<h && j+lw[p]>=0 && j+lw[p]<w && grid[i+lh[p]][j+lw[p]] == '.') {
						v[i][j].push_back({i+lh[p], j+lw[p]});
//						cout << i << j << p << endl;
					}
				}
			} else {
				grw[i] = 1;
				gcl[j] = 1;
			}
		}
	}
	vector<pair<int, int>> ini;
	fori(h) {
		if(grw[i] == 0) {
			forj(w) {
				if(gcl[j] == 0) ini.push_back({i,j});
			}
		}
		
	}
//	for(auto i:grw) cout << i << ' ';
//	cout << '\n';
//	for(auto i:gcl) cout << i << ' ';
//	for(auto i:ini) {
//		cout << i.fi << ' '<< i.se << '\n';
//	}
//	
	for(auto i: v) {
		for(auto j:i) {
			for(auto p:j) {
				cout << p.fi << ' '<< p.se << "   ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
	vector<vector<int>> dist(h, vector<int>(w, 1e9));
	queue<pair<int, int>> q;
	for(auto i:ini) {
		q.push({i});
		dist[i.fi][i.se] = 0;
	}
	
	while(!q.empty()) {
		pair<int, int> c = q.back();
		int cd = dist[c.fi][c.se];
		q.pop();
		for(auto i:v[c.fi][c.se]) {
			if(dist[i.fi][i.se]>cd+1) {
				dist[i.fi][i.se]=cd+1;
				q.push({i.fi,i.se});
			}
		}
	}
	int ans = 0;
//	for(auto i:dist) {
//		for(auto j:i) {
//			cout << j << ' ';
////			if(j<=k) ans+=1;
//		}
//		cout << '\n';
//	}
	cout << ans;
}