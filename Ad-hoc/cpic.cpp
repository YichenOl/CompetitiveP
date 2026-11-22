#include "../bits/stdc++.h"
using namespace std;
#define here cout << "here" << endl

int main() {
	int r, c; cin >> r >> c;
	vector<vector<char>> loop(r+2, vector<char> (c+2, '.'));
	vector<pair<int, int>> v;
	for(int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cin >> loop[i][j];
		}
	}
	
	int x[5] = {0, 1, 0, -1, 0};
	int y[5] = {-1, 0, 1, 0, -1};
//	for(auto i:loop) {
//		for(auto j:i) cout << j << ' ';
//		cout << '\n';
//	}	
	for(int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			bool b = 0;
			if(loop[i][j]=='#') {
				bool l = 0;
				for(int p=0; p<5; p++) {
					if (loop[i+x[p]][j+y[p]] == '#') {
						if(l == 1) b = 1;
						l = 1;
//						cout << i+x[p] << ' ' << j+y[p] <<'\n';
					} else {
						l = 0;
					}
				}
				
				if(b == 1) {
					v.push_back({i, j});
				}
				if(v.size()==2) break;
			}
		}
		if(v.size()==2) break;
	}
	
	for(auto i:v) cout << i.first << ' '<< i.second << '\n';
	cout << v[0].first+1 << ' ' << v[0].second << '\n';
	cout << v[1].first+1 << ' ' << v[1].second << '\n';
}