#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>
#define fi first
#define se second

//partial
int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	vector<pii> fri(k);
	for(int i=0; i<k; i++) {
		cin >> fri[i].fi;
		cin >> fri[i].se;
	}
	
	vector<vector<int>> adj(n, vector<int> (n, -1));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(adj[i][j]!=-1) continue;
			adj[i][j]=abs(v[i]-v[j]);
		}
	}
	for(auto i:fri) {
		adj[i.fi-1][i.se-1]=0;
		adj[i.se-1][i.fi-1]=0;
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	cout << 0 <<' ';
	pq.push({0, 0});
	vector<ll> dis(n, LLONG_MAX);
	while(!pq.empty()) {
		int time=pq.top().fi;
		int node=pq.top().se;
		pq.pop();
		if(dis[node]<time) continue;
		for(int i=0; i<n; i++) {
			if(i==node) continue;
			if(dis[i]>(time+adj[i][node])) {
				dis[i]=time+adj[i][node];
				pq.push({dis[i], i});
			}
		}
	}
	for(int i=1; i<n; i++) {
		cout << dis[i] <<' ';
	}
}