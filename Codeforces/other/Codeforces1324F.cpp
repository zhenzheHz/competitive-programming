// Problem : https://codeforces.com/problemset/problem/1324/F
// Tags : Tree DP, Rerooting DP
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
vector<int> g[MAXN], a(MAXN), dp(MAXN), rdp(MAXN), ans(MAXN);
void dfs(int cur, int from) {
    dp[cur] = a[cur];
    for(int &nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
        dp[cur] += max(dp[nxt], 0LL);
    }
}
void reroot(int cur, int from) {
    for(int &nxt : g[cur]) {
        if(nxt == from) continue;
        rdp[nxt] = dp[cur] + max(0LL, rdp[cur]) - max(0LL, dp[nxt]);
        reroot(nxt,cur);
    }
    ans[cur] = dp[cur] + max(0LL, rdp[cur]);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i] = a[i]? 1 : -1;
    for(int i=1;i<n;i++) {
        int src,des;
        cin >> src >> des;
        g[src].push_back(des);
        g[des].push_back(src);
    }
    dfs(1,-1);
    reroot(1,-1);
    for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i==n];
}