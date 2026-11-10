// Author : Zhenzhe
// Time : 2024 / 11 / 02
// Problem : https://zerojudge.tw/ShowProblem?problemid=c001
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    while(cin >> a >> b) {
        int dp[MAXN][MAXN];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=a.size();i++) {
            for(int j=1;j<=b.size();j++) {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[a.size()][b.size()] << '\n';
    }
}