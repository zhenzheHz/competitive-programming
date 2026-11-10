// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=b840
// Tag :  104 北二區 桃竹苗基 資訊學科能力 複賽 
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n+1][n+1],pref[n+1][n+1];
    memset(pref,0,sizeof(pref));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            pref[i][j] = pref[i][j-1] + arr[i][j];
        }
    }
    int ans = 0;
    for(int l = 1; l <= n; l++) {
        for(int r = l; r <= n; r++) {
            vector<int> g(n+1, 0), dp(n+1,0);
            for(int i = 1; i <= n; i++) {
                g[i] = pref[i][r] - pref[i][l-1];
            }
            for(int i = 1; i <= n; i++) {
                dp[i] = max(dp[i-1]+g[i], g[i]);
            }
            ans = max(ans, *max_element(dp.begin()+1, dp.end()));
        }
    }
    return cout<<ans,0;
}