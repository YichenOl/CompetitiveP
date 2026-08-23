#include "../bits/stdc++.h"
//ACed
using namespace std;
int main() {
	int test; cin >> test;
	while(test--) {
		int a, b; cin >> a >> b;
		int i = 0;
		while(++i) {
			if(b*i==a) {
				cout << "YES\n";
				break;
			} else if(b*i>a) {
				cout << "NO\n";
				break;
			}
		}
	}
}