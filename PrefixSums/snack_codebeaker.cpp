#include <bits/stdc++.h>
#include <list>
using namespace std;
typedef long long ll;
#define here cout << "yay"<< endl;
#define fori(x) for(int i = 0; i< x; i++)	
	//ACed
int main() {
	int n; cin >> n;
	vector<ll> ps(n);
	vector<ll> v(n);
	
	string s; cin >> s;
	for(int i = 0; i< n; i++) {
		if(s[i]=='M') v[i]=-2;
		else v[i]=s[i]-'0';
	}
	
	ps[0]=v[0];
	for(int i = 1; i< n; i++){
		ps[i]=max(v[i], v[i]+ps[i-1]);
	}
	
	sort(ps.begin(), ps.end());
	
	cout << ps.back();
}
