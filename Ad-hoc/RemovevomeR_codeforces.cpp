#include "../bits/stdc++.h"
using namespace std;
//ACed
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int zcnt = 0, ocnt = 0;
		int n; cin >> n;
		char prev; cin >> prev;
		for(int i=0; i<n-1; i++) {
			char a; cin >> a;
			if(a!=prev) {
				if(prev=='0') zcnt++;
				else ocnt++;
			}
			prev = a;
		}
		if(prev=='1') ocnt++;
		else zcnt++;
		if(zcnt==1&&ocnt==1) {
			cout << "2\n";
		} else {
			cout << "1\n";
		}
	}
}