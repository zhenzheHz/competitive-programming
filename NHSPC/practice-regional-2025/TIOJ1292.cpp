// Problem : https://tioj.ck.tp.edu.tw/problems/1292
// Tags : Tree DP
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
int dp[MAXN][2];
vector<int> g[MAXN];
void dfs(int cur, int from) {
    dp[cur][0] = 1, dp[cur][1] = 0;
    for(int &nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
        dp[cur][0] += min(dp[nxt][0],dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout << min(dp[1][0],dp[1][1]);
}