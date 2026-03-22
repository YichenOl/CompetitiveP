#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<string> w(n);
	int m=0;
	for(int i =0; i < n; i++) {
		cin >>w[i];
		m = max(int(w[i].length()), m);
	}
	
	for(string i:w) {
		int x = (m-i.length())/2;
		for(int i =0; i < x; i++) {
			cout << '.';
		}
		cout << i;
		for(int i =0; i < x; i++) {
			cout << '.';
		}
		cout <<'\n';
	}
}