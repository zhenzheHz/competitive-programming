// Problem : https://codeforces.com/contest/2136/problem/C
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> dp(n+1,0);
    vector<deque<int>> prev(n+1);
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        prev[x].push_back(i);
        dp[i] = dp[i-1];
        if((int)prev[x].size() > x) prev[x].pop_front();
        if((int)prev[x].size() == x) {
            dp[i] = max(dp[i], dp[prev[x].front() - 1] + x);
        }
        // cout << dp[i] << " \n"[i==n];
    }
    return cout<< dp[n] << '\n', void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}