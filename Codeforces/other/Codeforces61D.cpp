// Problem : https://codeforces.com/contest/61/problem/D
// Tags : Tree, DFS, Greedy, Shortest Path
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
vector<pair<int,int>> g[MAXN];
vector<int> dp(MAXN, 0);
void dfs(int cur, int from) {
    dp[cur] = 0;
    for(auto [nxt, w] : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
        dp[cur] = max(dp[cur], dp[nxt] + w);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    for(int i=1;i<n;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        g[a].push_back({b,x});
        g[b].push_back({a,x});
        ans += x;
    }
    dfs(1,1);
    ans <<= 1;
    ans -= *max_element(dp.begin()+1, dp.begin()+n+1);
    return cout<<ans<<'\n',0;
}