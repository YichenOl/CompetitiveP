#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>
#define fi first
#define se second
#define int ll
//partial
int32_t main() {
	int n; cin >> n;
	ll ans = 0;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	int x=(n-1)/2;
	int y=n-1-x;
	for(int i=1; i<=x; i++) {
		ans += i*b[i];
	}
	for(int i=x+1; i<n; i++) {
		ans += (n-i)*b[i];
	}
	cout << ans;
}	