#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2005;
// string grid[MAXN];
// int dp[MAXN][MAXN][2];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    int dp[n][m][2];
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
            // cerr << dp[i][j] << " \n"[j == m-1];
        }
    }
    if (grid[0][0] == '#') dp[0][0][1] = 1;
    else dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            int sum0 = 0, sum1 = 0;
            if (i > 0) {
                sum0 = (sum0 + dp[i-1][j][0]) % MOD;
                sum1 = (sum1 + dp[i-1][j][1]) % MOD;
            }
            if (j > 0) {
                sum0 = (sum0 + dp[i][j-1][0]) % MOD;
                sum1 = (sum1 + dp[i][j-1][1]) % MOD;
            }
            if (grid[i][j] == '#') {
                dp[i][j][0] = sum1;
                dp[i][j][1] = sum0;
            } else {
                dp[i][j][0] = sum0;
                dp[i][j][1] = sum1;
            }
        }
    }
    cout << dp[n-1][m-1][1] << '\n';
}