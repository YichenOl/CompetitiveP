#include <bits/stdc++.h>
#include <list>
using namespace std;
typedef long long ll;
#define here cout << "yay"<< endl;
#define fori(x) for(int i = 0; i< x; i++)	

int main() {
	int n; cin >> n;
	vector<ll> v(n);
	for(int i =0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (ll i:v) {
		cout << i <<'\n';
	}
}