#include "../bits/stdc++.h"

using namespace std;
int main() {
	int n; cin >> n; int ans =0;
	vector<int> v(n);
	for(int &i:v) {
		cin >> i;
	}
	
	sort(v.begin(),v.end());
	while(true) {
		vector<int>::iterator lb = lower_bound(v.begin(), v.end(), 0);
		vector<int>::iterator ub = upper_bound(v.begin(), v.end(), 0);

		if(lb==v.end()&&up==v.end()) break;
		if(*ub-0)
	}
}