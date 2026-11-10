// Problem : https://atcoder.jp/contests/abc401/tasks/abc401_c
// Tags : Sliding Window
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 1e9;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> dp(n+1, 1);
    for(int i = k, sum = k; i <= n; i++) {
        dp[i] = sum;
        sum += dp[i] - dp[i-k] + MOD;
        sum %= MOD;
    }
    return cout << dp[n], 0;
}