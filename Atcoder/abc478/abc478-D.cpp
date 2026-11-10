// Author : zhenzhe
// 2026/10/03 Sat 20:21:10
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
    int n, Q;
    cin >> n >> Q;
    map<int, vector<pair<int, int>>> f;
    for (int i = 0; i < Q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        f[c].push_back({l, r});
    }

    vector<int> mark(n + 5, 0);

    for (auto &[c, seg] : f) {
        sort(all(seg));

        int curL = -1, curR = -1;
        for (auto [l, r] : seg) {
            if (l > curR) {
                if (curL != -1) {
                    mark[curL]++;
                    mark[curR + 1]--;
                }
                curL = l;
                curR = r;
            } else {
                curR = max(curR, r);
            }
        }
        if (curL != -1) {
            mark[curL]++;
            mark[curR + 1]--;
        }
    }

    for (int i = 1, _pref = 0; i <= n; i++) {
        _pref += mark[i];
        cout << _pref << ' ';
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
