#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, d, k;
	cin >> n >> d >> k;
	
	vector<ll> mon(n);
	for(int i = 0; i<n; i++) {
		cin >> mon[i];
	}
	
	vector<ll> lim(d);
	for(int i = 0; i<d; i++) {
		cin >> lim[i];
	}
	
	sort(mon.begin(), mon.end(), greater<int>());
	vector<ll> ps(n+1);
	ps[0]=0;
	ps[1]=mon[0];
	for(int i = 2; i<=n; i++) {
		ps[i]=ps[i-1]+mon[i-1];
	}
	
	for(int i = 0; i<d; i++) {
		ll ans = 0;
		ll x=lim[i];
		if(x>=n) {
			cout << ps[n/(k+1)]+ps[n]<<'\n';
			continue;
		}
		cout << ps[x/(k+1)]+ps[x]<<'\n';
	}

}