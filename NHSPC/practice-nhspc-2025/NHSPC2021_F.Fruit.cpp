// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2256
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 45, SIGN = 45*45+5, INF = 1e18;
int n,budget,p[MAXN],s[MAXN],num[MAXN],dp[MAXN][SIGN],r[MAXN][MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> budget;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> num[i];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= i; j++) cin >> r[i][j];
    for(int i = 1; i <= n; i++) {
        p[i] += p[i-1], num[i] += num[i-1];
        for(int j = 1; j <= i; j++) r[i][j] += r[i][j-1];
    }
    for(int i = 0; i <= n; i++) for(int j = 0; j <= num[n]; j++) dp[i][j] = INF;
    // for(int i = 0; i <= budget; i++) dp[0][i] = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= num[n]; j++) {
            // 'k' is the previous spot to unload before 'i'
            for(int k = 0; k < i; k++) {
                int cost = (num[i] - num[k]) * (p[i] + s[i]);
                int sell = r[i][i] - r[i][k];
                if(j >= sell && dp[k][j-sell] != INF) dp[i][j] = min(dp[i][j], dp[k][j-sell] + cost);
            }
        }
    }
    int ans = -1;
    // consider the cost of dumping the remaining fruits
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= num[n]; j++) {
            int dump_cost = (num[n] - num[i]) * p[n];
            if(dp[i][j] != INF && dp[i][j] + dump_cost <= budget) {
                ans = max(ans, j);
            }
        }
    }
    return cout << ans,0;
}