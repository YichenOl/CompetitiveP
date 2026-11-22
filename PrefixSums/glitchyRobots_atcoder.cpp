#include "../bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
	int n; cin >> n;
	vector<int> v(n);
	vector<int> ps;
	
	cin >> v[0];
	ps.push_back(v[0]);
	for(int i=1; i<n; i++) {
		cin >> v[i];
		ps.push_back(ps[i-1]+v[i]);
	}
//	ps.push_back(0);
	sort(ps.begin(), ps.end());
	
	vector<int> ans;
	
	ans.push_back(max(ps.back(),0LL)-min(ps.front(),0LL)+1);
//	cout << ans.back() <<' ';
	multiset<int> s(ps.begin(), ps.end());
	int bma = -1000000010, bmi = 1000000010, ama = ps.back(), ami = ps.front();
	for(int i=0; i<n; i++) {
		int c = v[i];
		if(i-1>=0) {
			int pre = v[i-1];
			if(pre == *s.rbegin()) s.erase(prev(s.end()));
			if(pre == *s.begin()) s.erase(s.begin());
			bma = max(bma, pre); 
			bmi = min(bmi, pre);
		}
		ama = *s.rbegin(), ami = *s.begin();
		int nma = max({bma, ama+(2*(-c)), 0LL});
		int nmi = min({bmi, ami+(2*(-c)), 0LL});
		ans.push_back(nma-nmi+1);
	}
//	for(auto i:ans) cout << i << ' ';
//	cout << '\n';
	
	sort(ans.begin(), ans.end());
	cout << ans.back();
}