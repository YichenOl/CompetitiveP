#include "../bits/stdc++.h"
using namespace std;

int main() {
	int test; cin >> test;
	while(test--) {
		vector<pair<int, int>> v = {{0, 1}, {0, 3}, {0, 2}};
		char ans;
		int t = 0;
		for(int i=0; i<3; i++) {
			int a; cin >> a;
			v[i].first = a;
			t+= v[i].first;
		}
		
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		
//		if(v[0].first==v[1].first && v[0].second==3 && v[1].second==1) {
//			ans = 1;
//		} else {
//			ans = v[0].second;
//		}
		ans = v[0].second;
		for(int i=0; i<t; i++) {
			if(ans == 1) cout << 'P';
			if(ans == 2) cout << 'S';
			if(ans == 3) cout << 'R';
		}
		cout << '\n';
	}
}