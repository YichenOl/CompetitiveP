#include "../bits/stdc++.h"
using namespace std;
//ACed
int main() {
	int f, d; cin >> f >> d;
	vector<vector<char>> v(f, vector<char> (d));
	for(auto &i:v) {
		for (auto &j:i) {
			cin >> j;
		}
	}
	bool b = 0;
	for(int i=0; i<f; i++) {
		for(int j=0; j<d; j++) {
			if(v[i][j]=='x') {
				b=1;
				if((j-1>=0&&v[i][j-1]=='o')||(j+1<f&&v[i][j+1]=='o')) {
					cout << "Drain " << j+1;
				} else {
					cout << "Faucet " << i+1;
				}
				break;
			}
		}
		if(b==1) break;
	}
}