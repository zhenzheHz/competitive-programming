#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<array<int, 3>>f(n);

    for(auto &i : f) cin>>i[0]>>i[1]>>i[2];

    sort(f.begin(), f.end(), [] (array<int, 3>&a, array<int, 3>&b) {
        return a[1] < b[1];
    });

    vector<int>dp(n,0);
    dp[0] = f[0][2];
    for(int i = 1; i < n; i++) {
        auto it = upper_bound(f.rbegin(), f.rend(), f[i][0], [] (int a, array<int, 3> b) {
            return a > b[1];
        });

        if(it == f.rend()) dp[i] = f[i][2];
        else dp[i] = dp[int(f.rend() - it) - 1] + f[i][2];

        dp[i] = max(dp[i], (i == 0 ? 0 : dp[i - 1]));
    }

    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}