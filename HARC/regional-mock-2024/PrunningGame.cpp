#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7,MAXN = 2e5+5;
int n,m;
vector<int> g[MAXN],depth(MAXN,-2);
void dfs(int cur,int from) {
    if(cur == 1) depth[1] = -1;
    else depth[cur] = depth[from] + 1;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    }
}
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b&1) return (a*fp(a,b-1));
    int h = fp(a,b>>1);
    return h*h%mod;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dp[MAXN], res = 1;
    dp[0] = 1;
    for(int i=1;i<MAXN;i++) {
        res = res*m %mod;
        dp[i] = (dp[i-1] + res) %mod;
        //cout << dp[i] << '\n';
    }
    dfs(1,1);
    int ans = 0;
    for(int i=2;i<=n;i++) {
        //cerr << depth[i] << '\n';
        ans += dp[depth[i]];
        ans %= mod;
    }
    cout << ans << '\n';
}