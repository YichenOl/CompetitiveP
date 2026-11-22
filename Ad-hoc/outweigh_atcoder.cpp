#include "../bits/stdc++.h"

typedef long long ll;
#define here cout << "here" << endl
using namespace std;
//ACed but it is so easy why???
int main() {
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	
	for(ll &i:a) cin >> i;
	for(ll &i:b) cin >> i;
	
	ll num = 1000000000000000000LL;
	vector<ll> ans;
	
	for(int i=0; i<n; i++) {
		if(a[i]>b[i]) {
			cout << "Yes\n";
			ans.push_back(num);
			for(int j=i+1; j<n; j++) {
				ans.push_back(1);
			}
			for(ll p:ans) cout << p << ' ';
			return 0;
			
		} else {
			ans.push_back(1);
		}
	}
	
	cout << "No";

}