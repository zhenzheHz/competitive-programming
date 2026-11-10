// Author : zhenzhe
// 2026/10/03 Sat 21:13:47
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
static constexpr int MAXN = 2e5 + 5;


vector<int> g[MAXN], rg[MAXN], ord;
int comp[MAXN];
bool vis[MAXN];

void dfs1(int u) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : rg[u])
        if (comp[v] == -1) dfs2(v, c);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> E(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        E[i] = {w, u, v};
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    fill(comp, comp + n + 1, -1);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs1(i);

    int C = 0;
    for (int i = n - 1; i >= 0; i--)
        if (comp[ord[i]] == -1) dfs2(ord[i], C++);

    vector<vector<pair<int, int>>> dag(C);
    vector<int> indeg(C, 0);
    for (auto &[w, u, v] : E) {
        int a = comp[u], b = comp[v];
        if (a == b) {
            if (w == 1) {
                cout << "No\n";
                return;
            }
        } else {
            dag[a].push_back({b, w});
            indeg[b]++;
        }
    }

    vector<int> dp(C, 1);
    queue<int> q;
    for (int i = 0; i < C; i++)
        if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : dag[u]) {
            chmax(dp[v], dp[u] + w);
            if (--indeg[v] == 0) q.push(v);
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << dp[comp[i]] << " \n"[i == n];
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
