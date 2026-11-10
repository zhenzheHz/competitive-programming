// Author : zhenzhe
// 2026/10/22 Thu 18:05:10
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

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
static constexpr int INF = 4e18;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> cost(n, vector<int>(m));
    for (auto &v : cost) {
        for (auto &x : v) cin >> x;
    }

    vector<int> d(m);
    for (auto &x : d) cin >> x;

    if (n <= m) {
        // 情況一：n 較小，使用 Bitmask DP
        vector<int> dp(1 << n, INF);
        dp[0] = 0;

        for (int i = 0; i < m; i++) {
            // curr 代表從現有狀態出發，考慮在第 i 個賣家買東西的結果
            vector<int> curr = dp;

            // 對第 i 個賣家的每個化學品進行 0/1 背包轉移
            for (int j = 0; j < n; j++) {
                vector<int> next_curr = curr;
                for (int mask = 0; mask < (1 << n); mask++) {
                    if (curr[mask] != INF) {
                        chmin(next_curr[mask | (1 << j)], curr[mask] + cost[j][i]);
                    }
                }
                curr = next_curr;
            }

            // 如果買了任何化學品（mask > 0），必須加上第 i 個賣家的固定運費 d[i]
            for (int mask = 1; mask < (1 << n); mask++) {
                if (curr[mask] != INF) {
                    curr[mask] += d[i];
                }
            }

            // 將第 i 個賣家的選擇結果合併回全局 dp
            for (int mask = 0; mask < (1 << n); mask++) {
                chmin(dp[mask], curr[mask]);
            }
        }
        cout << dp[(1 << n) - 1] << '\n';
    } else {
        // 情況二：m 較小（n > m），直接枚舉 2^m 個賣家子集
        int ans = INF;
        int total_masks = (1 << m);
        for (int mask = 1; mask < total_masks; mask++) {
            int cur_cost = 0;
            for (int j = 0; j < m; j++) {
                if ((mask >> j) & 1) {
                    cur_cost += d[j];
                }
            }

            bool possible = true;
            for (int i = 0; i < n; i++) {
                int min_p = INF;
                for (int j = 0; j < m; j++) {
                    if ((mask >> j) & 1) {
                        chmin(min_p, cost[i][j]);
                    }
                }
                cur_cost += min_p;

                // 剪枝
                if (cur_cost >= ans) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                chmin(ans, cur_cost);
            }
        }
        cout << ans << '\n';
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
