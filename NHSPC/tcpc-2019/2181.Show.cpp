// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2018 北市賽 
// Tags : 0/1背包問題(動態規劃)
// Problem : https://tioj.ck.tp.edu.tw/problems/2181
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int limit, n;
    cin >> limit >> n;
    int cost[1005], value[1005], dp[1005][1005];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) cin >> value[i] >> cost[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=limit;j++) {
            if(cost[i] <= j)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int maxS = 0, Cost = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=limit;j++) {
            // cout << dp[i][j] << " \n"[j==limit];
            if(dp[i][j] > maxS) {
                maxS = dp[i][j];
                Cost = j;
            }else if(dp[i][j] == maxS) {
                Cost = min(Cost, j);
            }
        }
    }
    cout << maxS << ' ' << Cost << '\n';
}