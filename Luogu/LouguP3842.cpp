// Problem : https://www.luogu.com.cn/problem/P3842#ide
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e4+5;
int dp[MAXN][2];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> L(n),R(n);
    for(int i=0;i<n;i++) cin >> L[i] >> R[i];
    dp[0][1] = R[0] - 1;
    dp[0][0] = R[0] - 1 + R[0] - L[0];
    for(int i=1;i<n;i++) {
        int len = R[i] - L[i];
        dp[i][0] = min(dp[i-1][0] + abs(R[i]-L[i-1]) + len,
                       dp[i-1][1] + abs(R[i]-R[i-1]) + len) + 1;
        dp[i][1] = min(dp[i-1][0] + abs(L[i]-L[i-1]) + len,
                       dp[i-1][1] + abs(L[i]-R[i-1]) + len) + 1;
    }
    return cout<<min(dp[n-1][0] + n - L[n-1], dp[n-1][1] + n - R[n-1]),0;
}