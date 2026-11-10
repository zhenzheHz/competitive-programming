// Problem : https://codeforces.com/contest/2069/problem/C
// Tags : DP
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<vector<int>> dp(n,vector<int> (3,0));
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) {
        if(v[i] == 1) {
            dp[i][1] = (dp[i-1][1] + 1) % mod;
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
        if(v[i] == 2) {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = (dp[i-1][2] * 2 + dp[i-1][1]) % mod;
            dp[i][3] = dp[i-1][3];
        }
        if(v[i] == 3) {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = (dp[i-1][2] + dp[i-1][3]) % mod;
        }
    }
    return cout<<dp[n][3],void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}