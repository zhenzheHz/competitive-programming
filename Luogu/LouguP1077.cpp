// Problem : https://www.luogu.com.cn/problem/P1077
// Tag : dp + prefix sum
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 105, mod = 1e6+7;
int dp[MAXN][MAXN], pref[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i=0;i<=m;i++) pref[i] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            int index = j - min(j,a[i]) - 1;
            if(index < 0) dp[i][j] = (dp[i][j] + pref[j]) % mod;
            else dp[i][j] = (dp[i][j] + pref[j] - pref[index] + mod * 2) % mod;
        }
        pref[0] = dp[i][0];
        for(int k=1;k<=m;k++) pref[k] = pref[k-1] + dp[i][k];
    }
    // for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) cout << dp[i][j] << " \n"[j==m];
    cout << dp[n][m]%mod << '\n';
}