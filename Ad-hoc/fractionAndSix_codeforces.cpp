#include "../bits/stdc++.h"
using namespace std;

int main() {
	int n; cin >> n;
	while (n--) {
		bool w = 0;
		map<char, int> m;

		int a, b; cin >> a >> b;
		for(int i=0; i<a; i++) {
			char t; cin >> t;
			m[t] += 1;
		}
		
		for(int i=0; i<b; i++) {
			char t; cin >> t;
//			cout << t;
			if(m[t] > 0) {
				m[t] -= 1;
			} else {
				w = 1;
			}
		}
		
		if(w == 1) {
//			cout << 'h';
			cout << "NO\n";
			continue;
		}
		
		if(m['s']==1 && m['i']==1 && m['x']==1) {
			m['s']--;
			m['i']--;
			m['x']--;
		} else {
			cout << "NO\n";
			continue;
		}
		
		w = 0;
		for(auto i:m) {
			if(i.second != 0) {
				cout << "NO\n";
				w=1;
				break;
			}
		}
		if(w==0) cout << "YES\n";
		
	}
}