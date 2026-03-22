#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>
#define fi first
#define se second
#define int ll
//ACed finally("-ࡇ-)
int32_t main() {
	int n; cin >> n;
	ll ans = 0;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	
	vector<int> move(n-1);
	move[0]=a[0]-b[0];
	for(int i=1; i<n-1; i++) {
		move[i]=a[i]-b[i]+move[i-1];
	}
	
	move.push_back(0);
	sort(move.begin(), move.end());
	int k = move[(n)/2+((n)%2)-1];
	for(auto i:move) {
		ans += abs(i-k);
	}
	cout << ans;
}
