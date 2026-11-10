#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, md = 1e9+7;
vector<int> g[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1]=1;
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1]*4 - dp[i-2] + md * 3;
        dp[i]%= md;
    }
    cout << dp[n] <<endl;
}