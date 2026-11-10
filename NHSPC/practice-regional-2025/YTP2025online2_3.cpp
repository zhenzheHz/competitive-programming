// Author : Zhenzhe
// Problem : https://oj.ntucpc.org/problems/953
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> cost(n+1), dp(n+1);
    for(int i = 1; i <= n; i++) cin >> cost[i];
    dp[0] = 0, dp[1] = cost[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
    }
    return cout<<dp[n]-cost[n],0;
}