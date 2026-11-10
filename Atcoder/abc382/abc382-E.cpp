// Problem : https://atcoder.jp/contests/abc382/tasks/abc382_e
// Tags : Expected Value
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5005;
int P[MAXN];
double dp[MAXN][MAXN], f[MAXN], g[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    for(int i=1;i<=n;i++) cin >> P[i];
    // dp[0][0] = (100-P[0]) / 100.0;
    // dp[0][1] = P[0] / 100.0;
    // for(int i=1;i<n;i++) {
    //     const double ch = P[i] / 100.0;
    //     const double nch = (100 - P[i]) / 100.0;
    //     for(int j=0;j<=n;j++) {
    //         dp[i][j] = dp[i-1][j] * nch;
    //         if(j >= 1) dp[i][j] += dp[i-1][j-1] * ch;
    //     }
    // }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) {
        const double PRB = P[i] / 100.0;
        for(int j=0;j<=i;j++) {
            dp[i][j] = dp[i-1][j] * (1.0 - PRB);
            if(j >= 1) dp[i][j] += dp[i-1][j-1] * PRB;
        }
    }
    //for(int i=0;i<n;i++) for(int j=0;j<=n;j++) cout << dp[i][j] << " \n"[j==n];
    for(int i=0;i<=n;i++) g[i] = dp[n][i];
    f[0] = 0;
    const double TERM = (1.0 - g[0]);
    for(int i=1;i<=x;i++) {
        double sigma = 1.0;
        for(int j=1;j<=i;j++) {
            sigma += g[j] * f[i-j];
        }
        f[i] = sigma / TERM;
    }
    return cout<<fixed<<setprecision(15)<<f[x],0;
}