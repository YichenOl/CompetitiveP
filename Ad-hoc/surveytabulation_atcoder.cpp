#include "../bits/stdc++.h"
//ACed
using namespace std;
int main() {
	int t; cin >> t;
	unordered_map<string, int> m;

	while(t--) {
		string a; cin >> a;
		string b = "";
		for(char i:a) {
			if(int(i)<=90) b += char(i+32);
			else b+=i;
		}
		m[b]++;
	}
	vector<int> v;
	for(const auto &i:m) {
		v.push_back(i.second);
	}
	sort(v.begin(),v.end());
	cout << v.back();
}