#include "../bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
	int n; cin >> n;
	
	vector<int> v(n);
	vector<int> bl;
	
	int prev = -1;
	for(int i=0; i<n; i++) {
		cin >> v[i];
		if(v[i]!=prev) {
			bl.push_back(1);
		} else {
			bl.back()++;
		}
		prev = v[i];
	}
	//find len of each sim color block
	
	vector<int> ans(n);
	prev = -1;
	int cnt = 0;
	int total = 0;
	int cur = 0;
	for(int i=0; i<n; i++) {
		//handle fir
		if(i<bl.front()){
			ans[i]=bl.front()-i;
			prev = v[i];
			continue;
		}
		
		//if diff from prev switch block
		
		if(prev!=v[i]) {
			cnt+=1;
			cur = bl[cnt];
//			cout << prev << ' ' << v[i] <<' ' << cur <<'\n';
			total += bl[cnt-1];
		}
		//handle last
		if(i>=(n-bl.back())) {
			ans[i]=i-total+1;
			prev = v[i];
			continue;
		}
		
		int x = i+1-total;
		if(cur==1||x<=cur/2) {
			ans[i] = x;
		} else {
			ans[i] = cur-x+1;
//			cout << i <<' '<< cur << x <<'\n';
		}
		prev = v[i];
	}
	//manual handle fi and la block
	
	//if mid or lower, cal length+1, higher len +1
	for(int i:ans) cout << i << ' ';
}