// Author : zhenzhe
// 2026/10/05 Mon 16:20:56
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
static constexpr int MAXN = 1e5 + 5;

vector<int> G[MAXN];
vector<int> dfn(MAXN, 0), low(MAXN, 0), scc_id(MAXN, 0);
vector<int> stk;
vector<bool> inStk(MAXN,0);

int timer = 0, __scc = 0;

void dfs_tarjan(int cur) {
    dfn[cur] = low[cur] = ++timer;
    stk.push_back(cur);
    inStk[cur] = 1;
    for(auto &nxt : G[cur]) {
        if(dfn[nxt] == 0) {
            dfs_tarjan(nxt);
            low[cur] = min(low[cur], low[nxt]);
        }
        else if(inStk[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    
    if(dfn[cur] == low[cur]) {
        for(; !stk.empty(); ) {
            int nxt = stk.back();
            stk.pop_back();
            inStk[nxt] = 0;
            scc_id[nxt] = __scc;
            if(cur == nxt) break;
        }
        __scc++;
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> f(n+1);
    vector<pair<int,int>> edge;
    for(int i = 1; i <= n; i++) cin >> f[i];
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            dfs_tarjan(i);
        }
    }

    vector<int> w(__scc, 0), _G[__scc], degree(__scc, 0);
    for(int i = 1; i <= n; i++) {
        w[scc_id[i]] += f[i];
    }

    for(int u = 1; u <= n; u++) {
        for(auto &v : G[u]) {
            if(scc_id[u] != scc_id[v]) {
                _G[scc_id[u]].push_back(scc_id[v]);
                degree[scc_id[v]]++;
            }
        }
    }

    queue<int> q;

    for(int i = 0; i < __scc; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> dp = w;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto &nxt : _G[cur]) {
            if(--degree[nxt] == 0) {
                q.push(nxt);
            }
            dp[nxt] = max(dp[nxt], dp[cur] + w[nxt]);
        }
    }

    return cout << *max_element(all(dp)) << '\n', void();
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

