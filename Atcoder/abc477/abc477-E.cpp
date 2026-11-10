// Author : zhenzhe
// 2026/09/26 Sat 20:50:25
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
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n+1), b(n+1), pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++) cin >> b[i];

    auto min_dist = [&](int u, int v) {
        if(u > v) swap(u, v);
        int tmp = pref[v-1] - pref[u-1];
        return min(tmp, pref[n] - tmp);
    };

    vector<int> dist = b;

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n; i++) {
            int prev = (i == 1 ? n : i - 1);
            int w = (i == 1 ? a[n] : a[i - 1]);
            chmin(dist[i], dist[prev] + w);
        }
    }
    for (int k = 0; k < 2; k++) {
        for (int i = n; i >= 1; i--) {
            int next = (i == n ? 1 : i + 1);
            int w = a[i];
            chmin(dist[i], dist[next] + w);
        }
    }

    debug(dist);

    while (q--) {
        int s, t;
        cin >> s >> t;
        if (s > t) swap(s, t);
        if (t == n + 1) {
            cout << dist[s] << "\n";
        } else {
            cout << min(min_dist(s, t), dist[s] + dist[t]) << "\n";
        }
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
