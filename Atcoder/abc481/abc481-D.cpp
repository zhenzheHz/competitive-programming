// Author : zhenzhe
// 2026/10/24 Sat 20:17:34
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
// static constexpr int MOD = 998244353;
static constexpr int MAXN = 2e5 + 5;

vector<int> G[MAXN];

void solve() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    for(int i = 0; i <= n; i++) {
        sort(all(G[i]));
    }

    deque<int> q;
    vector<int> dist(n+1, -1);
    dist[s] = 0;
    q.push_back(s);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        int now = 0;
        for(auto &nxt : G[cur]) {
            int w = (now++ == 0 ? 0 : 1);
            if(dist[nxt] == -1 || dist[nxt] > dist[cur] + w) {
                dist[nxt] = dist[cur] + w;
                if(w == 0) {
                    q.push_front(nxt);
                } else {
                    q.push_back(nxt);
                }
            }
        }
    }
    return cout << dist[t] << '\n', void();
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
