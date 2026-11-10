// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=a540
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5,INF = 1e18;
void solve(int SIZE) {
    int Array[MAXN],dp[MAXN];
    // memset(dp,-INF,sizeof(dp));
    for(int i=0;i<SIZE;i++) {
        cin >> Array[i];
    }
    dp[0] = Array[0];
    for(int i=1;i<SIZE;i++) {
        dp[i] = max(Array[i],dp[i-1] + Array[i]);
        // cerr << dp[i] << ' ';
    }
    int Maximum = *max_element(dp,dp+SIZE);
    if(Maximum <= 0) cout << "Losing streak.\n";
    else cout << "The maximum winning streak is " << Maximum << ".\n";
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int SIZE;
    while(cin >> SIZE && SIZE>0) {
        solve(SIZE);
    }
}