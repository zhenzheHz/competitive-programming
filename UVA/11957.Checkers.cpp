// Author : Zhenzhe
// Time : 2024 / 11 / 08
// Problem : https://zerojudge.tw/ShowProblem?problemid=j122
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e6+7;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1,CASE = 1;
    cin >> test;
    char g[105][105];
    int dp[105][105];
    while(test--) {
        memset(dp,0,sizeof(dp));
        int n;
        cin >> n;
        pair<int,int> start = {-1,-1};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> g[i][j];
                if(g[i][j] == 'W') start = {i,j};
            }
        }
        dp[start.first][start.second] = 1;
        for(int i=start.first-1;i>=0;i--) {
            for(int j=0;j<n;j++) {
                if(g[i][j] == 'W') continue;
                if(g[i][j] == 'B') dp[i][j] = 0;
                else {
                    if(j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i+1][j-1])%mod;
                    if(j+1<n) dp[i][j] = (dp[i][j] + dp[i+1][j+1])%mod;
                    if(i+2 < n && j-2 >=0 && g[i+1][j-1] == 'B')
                        dp[i][j] += dp[i+2][j-2], dp[i][j] %= mod;
                    if(i+2 < n && j+2 <n && g[i+1][j+1] == 'B')
                        dp[i][j] += dp[i+2][j+2], dp[i][j] %= mod;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(g[0][i] == 'B') continue;
            ans += dp[0][i];
            ans %= mod;
        }
        cout << "Case " << CASE++ << ": " << ans << "\n";
    }
}