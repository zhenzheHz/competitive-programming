// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2019 北市賽 pD
// Tags : 樹上LCA(樹論)
// Problem : https://tioj.ck.tp.edu.tw/problems/2172
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
constexpr int logN = __builtin_clz(MAXN);
vector<int> g[MAXN];
int dp[MAXN][logN+1],depth[MAXN];
int n,m;
void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<=logN;i++) {
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
    }
    for(auto nxt : g[cur]) {
        if(nxt != from) dfs(nxt,cur);
    }
}
int lca(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b], bit = 0;
    while(diff) {
        if(diff & 1) a = dp[a][bit];
        diff >>= 1;
        bit += 1;
    }
    if(a == b) return a;
    for(int p=logN;p>=0;p--) {
        if(dp[a][p] == dp[b][p]) continue;
        a = dp[a][p];
        b = dp[b][p];
    }
    return dp[a][0];
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    memset(dp,0,sizeof(dp));
    cin >> n >> m;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    
    dfs(1,1);
    
    while(m--) {
        int a,b;
        cin >> a >> b;
        int ans = depth[a]+depth[b];
        cout << ans - depth[lca(a,b)]*2 << '\n';
    }
}