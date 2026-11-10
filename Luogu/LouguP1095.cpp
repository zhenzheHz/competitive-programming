// Problem : https://www.luogu.com.cn/problem/P1095
// Tag : greedy + dp
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int m,s,t;
    cin >> m >> s >> t;
    int dp[t+1];
    dp[0] = 0;
    for(int i=1;i<=t;i++) {
        if(m >= 10) m-=10, dp[i] = dp[i-1] + 60;
        else m += 4, dp[i] = dp[i-1];
    }
    for(int i=1;i<=t;i++) {
        dp[i] = max(dp[i],dp[i-1]+17);
        if(dp[i] >= s) return cout<<"Yes\n"<<i,0;
    }
    return cout<<"No\n"<<dp[t],0;
}