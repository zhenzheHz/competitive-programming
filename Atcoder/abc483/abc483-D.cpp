// Author : zhenzhe
// 2026/11/07 Sat 20:50:48
#include <bits/stdc++.h>
#include <magic_tree>
#include <slow>
#define int int64_t
using namespace std;
using namespace zz_library;
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for(auto &x : f) cin >> x;
    vector<int> pf(n + 1, 0);
    for(int i = 0; i < n; i++) {
        pf[i+1] = pf[i] + f[i];
    }
    Segment_tree<int, zkw> t;
    t.init(pf);
    int ans = t.query_max(0, n) - t.query_min(0, n) + 1;
    for(int i = 0; i < n; i++) {
        t.update(i + 1, n, -2 * f[i]);
        ans = max(ans, t.query_max(0, n) - t.query_min(0, n) + 1);
        t.update(i + 1, n, 2 * f[i]);
        debug(ans);
    }
    cout << ans << '\n';
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
