// Author : zhenzhe
// 2026/10/22 Thu 18:05:10
#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
// using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int> (m));
    for(auto &v : cost) for(auto &x : v) cin >> x;
    vector<int> d(m);
    for(auto &x : d) cin >> x;
    if(n < m) {
        vector<int> dp(1<<n, INF);
        dp[0] = 0;
        for(int i = 0; i < m; i++) {
            // cur for choose this shop
            vector<int> cur = dp;
            for(int j = 0; j < n; j++) {
                vector<int> nxt = cur;
                for(int mask = 0; mask < (1<<n); mask++) {
                    if(cur[mask] != INF) chmin(nxt[mask | (1<<j)], cur[mask] + cost[j][i]);
                }
                cur = nxt;
            }
            for(int mask = 1; mask < (1<<n); mask++) {
                if(cur[mask] < INF) cur[mask] += d[i];
            }
            for(int mask = 0; mask < (1<<n); mask++) {
                chmin(dp[mask], cur[mask]);
            }
        }
        return cout << dp[(1<<n)-1] << '\n', void();
    }
    else {
        int ans = INF;
        for(int mask = 1; mask < (1<<m); mask++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                if((mask >> j) & 1) sum += d[j];
            }
            for(int i = 0; i < n; i++) {
                int best = INF;
                for(int j = 0; j < m; j++) {
                    if((mask >> j) & 1) chmin(best, cost[i][j]);
                }
                sum += best;
            }
            chmin(ans, sum);
        }
        return cout << ans << '\n', void();
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
