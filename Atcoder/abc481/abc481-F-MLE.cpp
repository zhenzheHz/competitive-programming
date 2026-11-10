// Author : zhenzhe
// 2026/10/25 Sun 02:38:34
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
// #include <slow>
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
static constexpr int MOD = 998244353;
static constexpr int MAXN = 2e5 + 5;

struct Edge {
    int rk, u,v,w;
    bool operator<(const Edge &cmp) const {
        if(rk == cmp.rk) return w > cmp.w;
        return rk > cmp.rk;
    }
};

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> G(n+1);
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    } 
    std::priority_queue<Edge> pq;
    for(const auto &[nxt, w] : G[1]) {
        pq.push({0, 1, nxt, w});
    }
    vector<int> ans(n+1, 0), mark(n+1, -1);
    ans[1] = 0, mark[1] = 0;
    int id = 1;
    while(!pq.empty()) {
        auto [rk, cur, nxt, w] = pq.top();
        pq.pop();
        if(mark[nxt] >= 0) continue;
        mark[nxt] = ++id;
        ans[nxt] = (ans[cur] * 10 + w) % MOD;
        for(auto &[_nxt, c] : G[nxt]) {
            if(mark[_nxt] == -1) {
                pq.push({rk, nxt, _nxt, c});
            } 
        }
    }
    for(int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return;
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
