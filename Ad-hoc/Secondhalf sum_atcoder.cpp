#include "../bits/stdc++.h"
#define se second
#define fi first
#define fori(x) for(int i=0; i<x; i++)
#define forj(y) for(int j=0; j<y; j++)
	
using namespace std;
#define here cout << "here\n"<<endl
int main() {
	int n, k; cin >> n >> k; int ans = 0;
	map<int, int> m;
	fori(n) {
		int t; cin >> t;
		m[t]++;
	}
	
	map<int, int> num;
	for(auto i:m) {
		num[i.se]++;
	}
	
	auto lar = num.rbegin();
	
	ans += lar -> se;
	int maxi = lar -> first;
	
	if(num.size()!=1) lar++;

	if(lar->fi == maxi-1) {
		ans += lar->se;
	}
	
	cout << ans;
}