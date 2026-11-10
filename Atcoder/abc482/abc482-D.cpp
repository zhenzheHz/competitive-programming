// Author : zhenzhe
// 2026/10/31 Sat 20:11:51
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n), l(n), r(n);
    for(auto &x : f) cin >> x;
    for(int i = 0; i < n; i++) {
        l[i] = (f[i] - f[0]) / 2;
        r[i] = (f[n-1] - f[i]) / 2;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) { cout << r[i] << '\n';continue; }
        if(i == n-1) { cout << l[i] << '\n';continue; }
        int lc = (f[i] - f[i-1]) >> 1;
        int rc = (f[i+1] - f[i]) >> 1;
        int ans = min(lc + max(r[i], l[i-1]), rc + max(l[i], r[i+1]));
        cout << ans << '\n';
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
