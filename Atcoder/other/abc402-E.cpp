// Problem : https://atcoder.jp/contests/abc402/tasks/abc402_e
// Tags : bitmask DP
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    vector<int> s(n), c(n), p(n);
    vector<vector<double>> dp(x+1, vector<double> (1<<n|1, 0.0));
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> c[i] >> p[i];
    }
    for(int i = 0; i <= x; i++) {
        for(int mask = 0; mask < (1<<n); mask++) {
            for(int k = 0; k < n; k++) {
                int rest = i - c[k];
                int st = mask | (1 << k);
                if(rest < 0 || st == mask) continue;
                double score = (p[k] / 100.0) * (dp[rest][st] + s[k]) + (1 - p[k] / 100.0) * dp[rest][mask];
                dp[i][mask] = max(dp[i][mask], score);
            }
        }
    }
    return cout << fixed << setprecision(15) << dp[x][0], 0;
}