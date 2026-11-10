// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2368
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3005, INF = 1e18;
vector<int> RG[MAXN], dp(MAXN,INF);
bool done[MAXN], safe[MAXN], vis[MAXN];
int n,m,u,v,s,t;
void dfs(int cur,bool *mark) {
    mark[cur] = 1;
    for(auto nxt : RG[cur]) {
        if(!mark[nxt]) dfs(nxt,mark);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        RG[v].push_back(u);
    }
    cin >> s >> t;
    int rest = n;
    dfs(t,safe);
    for(int i = 1; i <= n; i++) {
        if(!safe[i]) done[i] = 1, rest--;
    }
    dp[t] = 0;
    while(rest > 0) {
        int idx = 0, best = INF;
        for(int i = 1; i <= n; i++) {
            if(!done[i] && dp[i] < best) {
                best = dp[i], idx = i;
            }
        }
        done[idx] = 1, rest--;
        // using coin
        for(auto nxt : RG[idx]) {
            if(!done[nxt]) dp[nxt] = min(dp[nxt], dp[idx]+1);
        }
        // randomly walking
        for(int i = 1; i <= n; i++) {
            vis[i] = (safe[i] && done[i]);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && !safe[i]) {
                dfs(i,vis);
            }
        }
        for(int i = 1; i <= n; i++) {
            if(!done[i] && !vis[i]) {
                dp[i] = min(dp[i],dp[idx]);
            }
        }
    }
    return cout << (dp[s] > n? -1 : dp[s]), 0;
}