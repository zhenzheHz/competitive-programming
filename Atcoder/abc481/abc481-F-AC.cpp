// Author : zhenzhe
// 2026/10/27 Tue 21:01:05
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
static constexpr int MOD = 998244353;
static constexpr int MAXN = 2e5 + 5;

struct Edge {
    int rank,w,node,dist;
    bool operator<(const Edge &cmp) const {
        return make_pair(rank, w) > make_pair(cmp.rank, cmp.w);
    }
};

vector<pair<int,int>> G[MAXN];

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }

    std::priority_queue<Edge> pq;
    vector<int> ans(n+1,-1);
    int rk = 0;
    ans[1] = 0;
    pair<int,int> last = {-1,-1};
    for(const auto &[v,w] : G[1]) {
        pq.push({0, w, v, w});
    }   
    while(!pq.empty()) {
        const auto [r,w,cur,d] = pq.top();
        // debug(r,w,cur,d,ans[cur]);
        pq.pop();
        if(ans[cur] != -1) continue;
        if(make_pair(r,w) != last) {
            rk++, last = {r,w};
        }
        ans[cur] = d;
        // debug(ans[cur]);
        for(const auto &[nxt, _w] : G[cur]) {
            if(ans[nxt] == -1) {
                pq.push({rk, _w, nxt, (10 * d + _w) % MOD});
            }
        }    
    }
    for(int i = 2; i <= n; i++) {
        cout << ans[i] << '\n';
    }
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
