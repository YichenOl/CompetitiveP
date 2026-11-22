#include "../bits/stdc++.h"
using namespace std;
#define se second
#define fi first
#define int long long
//ACed
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, vo; cin >> n >> vo;
	vector<pair<int,int>> v(n);
	vector<map<int, int>> m(n);
	for(int i=0; i<n; i++) {
		v[i]={0,1+i};
	}
	
	for(int i=0; i<vo; i++) {
		int a, b; cin >> a >> b;
		v[a-1].fi++;
		m[a-1][b]++;
	}
	
	vector<pair<int,int>> v2(n);
	v2 = v;
	sort(v2.begin(), v2.end(), [](pair<int,int> a, pair<int,int> b) {
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});
	
	for(int i=0; i<n; i++) {
		pair<int, int> ma = v2[n-1];
		if(v2.back().se == i+1) {
			ma = v2[n-2];
//			auto tem = v2[n-1];
//			tem.first -= v[v2[n-1].se-1].fi;
//			if(tem.first > ma.first) {
//				ma = tem;
//			}
		}
		for(auto j:m[i]) {
			int ind = j.fi;
			int amt = j.se;
			int votes = v[ind-1].first+amt;
			if(votes > ma.fi || (votes == ma.fi && ind < ma.se)) {
				ma = {votes, ind};
			}
		}
		cout << ma.se << '\n';
	}
}