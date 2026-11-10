// Author : Zhenzhe
// Time : 2025 / 08 / 13
// Problem : https://codeforces.com/contest/2110/problem/D
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> b(n+1);
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=1;i<=n;i++){
        cin >> b[i];
        // g[i].clear();
    }
    for(int i=0;i<m;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        g[x].push_back({y,w});
    }
    function<bool(int)> check = [&](int limit) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++) {
            if(i>1 && dp[i] == 0) continue;
            dp[i] += b[i];
            dp[i] = min(dp[i], limit);
            for(auto nxt : g[i]) {
                if(dp[i] >= nxt.second) {
                    dp[nxt.first] = max(dp[nxt.first], dp[i]);
                }
            }
        }
        return dp[n]>0;
    };
    int l = -1, r = 1e9+1;
    while(l+1!=r) {
        int mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == (int)1e9+1) return cout<<"-1\n",void();
    else return cout<<r<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) solve();
}