#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6+5;
vector<int> g[MAXN], mark(MAXN);
int dp[MAXN][2];
void dfs(int cur,int from) {
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
        dp[cur][0] += dp[nxt][mark[cur]];
        dp[cur][1] += dp[nxt][mark[cur]];
    }
    dp[cur][!mark[cur]] += 1;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> mark[i];
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    cout << dp[1][0] << '\n';
}