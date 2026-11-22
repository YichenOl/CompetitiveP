#include "../bits/stdc++.h"
//ACed:D
using namespace std;
int main() {
	int n, q; cin >> n >> q;
	vector<int> P(n);
	for(int i=0; i<n; i++) cin >> P[i];
	vector<int> Q(q);
	for(int i=0; i<q; i++) cin >> Q[i];
	
	reverse(Q.begin(), Q.end());
//	for(int i:Q) cout << i << ' ';
	map<int, int> m;
	vector<int> eq;
	for(int i:Q) {
		if(m[i]==0) {
			
			m[i]++;
			eq.push_back(i);
//			cout << i << ' ';
		}
	}
	
	for(int i:P) {
		if(m[i]==0) cout << i << ' ';
	}
	reverse(eq.begin(), eq.end());

	for(int i:eq) cout << i << ' ';
}