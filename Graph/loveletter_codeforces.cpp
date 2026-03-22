#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>
#define fi first
#define se second

//ACed!
int main() {
	int n, k; cin >> n >> k;
	vector<pii> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i].fi;
		v[i].se=i;
	}
	vector<pii> fri(k);
	for(int i=0; i<k; i++) {
		cin >> fri[i].fi;
		cin >> fri[i].se;
	}
	
	sort(v.begin(), v.end());
	vector<vector<pair<int, int>>> adj(n);
	for(int i=0; i<n-1; i++) {
		adj[v[i].se].push_back({v[i+1].fi-v[i].fi, v[i+1].se});
		adj[v[i+1].se].push_back({v[i+1].fi-v[i].fi, v[i].se});
	}
	
	for(auto i:fri) {
		adj[i.fi-1].push_back({0, i.se-1});
		adj[i.se-1].push_back({0, i.fi-1});
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
		for(auto i:adj[node]) {
			if(dis[i.se]>(time+i.fi)) {
				dis[i.se]=(time+i.fi);
				pq.push({dis[i.se], i.se});
			}
		}
	}
	for(int i=1; i<n; i++) {
		cout << dis[i] <<' ';
	}
}
