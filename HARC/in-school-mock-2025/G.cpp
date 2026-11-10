#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int INF = 1e18;
#define f(x,y) (A+B*max(0LL,y-x)+C*max(0LL,x-y)+D*llabs(x-y))
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,A,B,C,D;
    cin >> n >> A >> B >> C >> D;
    vector<int> F(n+1);
    for(int i=1;i<=n;i++) cin >> F[i];
    F[0] = 1;
    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    dp[0][0] = 0;
    dp[1][0] = f(1,F[1]);
    for(int i=2;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]+f(F[i-1],F[i]));
            dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + f(F[j],F[i]));
        }
    }
    int ans = INF;
    for(int i=0;i<=n;i++) ans = min(ans,dp[n][i]);
    return cout<<ans,0;
}