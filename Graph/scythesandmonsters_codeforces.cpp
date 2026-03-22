#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pii pair<int, int>

bool cmp(pii a, pii b) {
	if(a.fi==b.fi) return a.se<b.se;
	return a.fi<b.fi;
}

int main() {
	int n, m; cin >> n >> m;
	int ans = 0;
	vector<pair<int, int>> ab(n);
	vector<int> d(m);
	for(int i=0; i<n; i++) cin >> ab[i].fi;
	for(int i=0; i<n; i++) cin >> ab[i].se;
	for(int i=0; i<m; i++) cin >> d[i];
	sort(ab.begin(), ab.end(), cmp);
	sort(d.begin(), d.end(), greater<int>());
	while(!ab.empty()) {
		if(d.back()>=ab.back().fi&&d.back()<=ab.back().se) {
			ans += 1;
			ab.pop_back();
			d.pop_back();
		} else {
			ab.pop_back();
		}
	}
	cout << ans;
}