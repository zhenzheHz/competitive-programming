#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int Convert(int y,int m,int d) {
    int result = (y - 2025) * 365;
    for(int i = 1; i < m; i++) {
        result += days[i];
    }
    result += d;
    return result;
}
void solve(int n) {
    int ans = 0,sy,sm,sd,ey,em,ed;
    vector<int> startTime(n), endTime(n), profit(n);
    for(int i = 0; i < n; i++) {
        cin >> sy >> sm >> sd >> ey >> em >> ed >> profit[i];
        startTime[i] = Convert(sy,sm,sd);
        endTime[i] = Convert(ey,em,ed);
    }
    vector<int> idx(n), r(n), dp(n,0);
    for(int i = 0; i < n; i++) idx[i] = i, r[i] = endTime[i];
    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return endTime[a] < endTime[b];
    });
    sort(r.begin(), r.end());
    for(int i = 0; i < n; i++) {
        auto f = upper_bound(r.begin(), r.end(), startTime[idx[i]]) - r.begin() - 1;
        dp[i] = profit[idx[i]];
        if(f >= 0) dp[i] = max(dp[i], dp[f] + profit[idx[i]]);
        if(i > 0) dp[i] = max(dp[i], dp[i-1]);
    }
    ans = *max_element(dp.begin(),dp.end());
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        solve(n);
    }
    return 0;
}
