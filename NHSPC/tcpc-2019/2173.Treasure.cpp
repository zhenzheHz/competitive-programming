// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2019 北市賽 pE
// Tags : 動態規劃
// Problem : https://tioj.ck.tp.edu.tw/problems/2173
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 105;
int n,m,dp[MAXN*2+1][MAXN][MAXN], g[MAXN][MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> g[i][j];
        }
    }
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[1][1][1] = g[1][1];
    for(int t=1;t<=n+m-1;t++) {
        for(int i=1;i<=min(n,t);i++) {
            for(int j=1;j<=min(n,t);j++) {
                if(i == 1 && j == 1 && t == 1) continue;
                if(g[i][t+1-i] == -1 || g[j][t+1-j] == -1) {
                    dp[t][i][j] = -0x3f3f3f3f; 
                    continue;
                }
                dp[t][i][j] = max({dp[t-1][i][j],dp[t-1][i-1][j],dp[t-1][i][j-1],dp[t-1][i-1][j-1]});
                if(i == j) dp[t][i][j] += g[i][t+1-i];
                else dp[t][i][j] += g[i][t+1-i] + g[j][t+1-j];
            }
        }
    }
    cout << max((int)0, dp[n+m-1][n][n]) << '\n';
}