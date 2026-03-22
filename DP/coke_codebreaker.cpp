#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
//ACed
//thanks to leyi ╥﹏╥
vector<pair<int, int>> val;
bool cmp(pair<int, int> a, pair<int, int> b) {
    long double c1=(float)a.fi/a.se;
    long double  c2=(float)b.fi/b.se;
    return c1>c2;
}

int32_t main() {
    int n, k; cin >> n >> k;
    val.assign(n+1, pair<int, int>({0, 0}));
    for(int i =1; i< n+1; i++) cin >> val[i].fi;
    for(int i =1; i< n+1; i++) cin >> val[i].se;

    sort(val.begin()+1, val.end(), cmp);
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    dp[0][0]=0;
    for(int i =1; i <n+1; i++) {
        for(int j =0; j <k+1; j++) {
            int e1 = dp[i-1][j];
            int e2;
            if(j-val[i].fi<0 or dp[i-1][j-val[i].fi]==-1) e2 = -1;
            else e2 = val[i].se*(j-val[i].fi)+dp[i-1][j-val[i].fi];
            dp[i][j] = max(e1, e2);
        }
    }
    
    int ans = 0;
    for(auto i:dp[n]) ans = max(ans, i);
    cout << ans;
}
