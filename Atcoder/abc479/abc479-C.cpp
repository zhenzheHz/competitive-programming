// Author : zhenzhe
// 2026/10/11 Sun 20:04:26
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
    int n,W;
    cin >> n >> W;
    vector<pair<int,int>> f(n);
    for(auto &[a,b] : f) cin >> a >> b;
    int ans = 0;
    for(int s = 1; s < (1<<n); s++) {
        int tmp = 0, w = 0;
        for(int i = 0; i < n; i++) {
            if((s >> i) & 1) {
                w += f[i].first;
                tmp += f[i].second;
            }
        }
        if(tmp > W) continue;
        chmax(ans, w);
    }
    return cout << ans, void();
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
