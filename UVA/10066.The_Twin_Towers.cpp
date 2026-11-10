// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=a133
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve(int CASE, int n, int m) {
    vector<int> a(n),b(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    int dp[n+1][m+1];
    memset(dp,0LL,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << "Twin Towers #" << CASE << '\n';
    cout << "Number of Tiles : " << dp[n][m] << "\n\n";
} 
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,CASE = 1;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        solve(CASE++, n, m);
    }
}