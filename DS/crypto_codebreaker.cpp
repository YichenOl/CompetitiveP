#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yay cout <<"yay"<< endl;

const ll M=1000000007;
vector<ll> dp(300000, -1);

class ftree {
    int n;
    vector<ll> tr;
    
public:
    ftree(ll s):n(s) {
        tr.resize(n+1, 0);
        for(int i =1; i<=n; i+=1) {
            tr[i]=i&(-i);
        }
    }
    
    void upd(ll x) {
        for(; x<=n; x+=x&(-x)) {
            tr[x]-=1;
        }
    }
    
    int qry(ll y) {
        int sum = 0;
        y-=1;
        for(; y>0; y-=y&(-y)) {
            sum+=tr[y];
        }
        return sum;
    }
};


int32_t main() {
    ll m; cin >> m;
    ll ans=0;
    dp[1]=1;
    
    map<ll, ll> nums;
    for(int i =0; i<m; i++) {
        ll t; cin >> t;
        nums.insert({t, i});
    }
    //precompute facs
    ll fac[300700];
    fac[0]=1;
    for(int i =1; i<300700; i++) {
        fac[i]= (i*fac[i-1])%M;
    }
    //compress nums by size order
    vector<ll> v(m);
    map<ll, ll>::iterator it = nums.begin();
    for(int i =0; i<m; i++) {
        v[it->second]=i+1;
        it++;
    }
    //call tree
    ftree tree(m);
    
    for(ll i =0; i<m; i++) {
        ans += ((tree.qry(v[i]))*fac[m-i-1])%M;
        tree.upd(v[i]);
    }
    cout << (ans+1)%M;
}
    