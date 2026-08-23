#include "../bits/stdc++.h"
#define fi first
#define se second
using namespace std;
typedef long long ll;
//ACed
bool nine(int a, int b) {
	if(a%9==0&&a/9==b) return true;
	else return false;
}

int32_t main() {
	int a, b;
	cin >> a >> b;
	if(a+b==9||a-b==9||a*b==9||nine(a, b)) cout << "Nine";
	else cout << "Nein";
}