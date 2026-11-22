#include "../bits/stdc++.h"
using namespace std;
//ACed
int main() {
	int n, q; cin >> n >> q;
	vector<pair<int, bool>> v(n+1);
	for(int i=1; i<=n; i++) {
		v[i]={i, 0};
	}
	
	vector<pair<int, bool>> v2(n+1);
	for(int i=1; i<=q; i++) {
		int f; cin >> f;
		for(int j=1; j<=f; j++) {
			v2[j].first = v[f-j+1].first;
			v2[j].second = !v[f-j+1].second;
		}
		for(int j=f+1; j<=n; j++) {
			v2[j] = v[j];
		}
		v = v2;
		v2.clear();
		v2.resize(n+1);
	}
	
	for(int i=1; i<=n; i++) {
		if(v[i].second == 0) {
			cout << v[i].first << '\n';
		} else {
			cout << -v[i].first << '\n';
		}
	}
	
}