// Author : Zhenzhe
// Time : 2025 / 08 / 13
// Problem : https://codeforces.com/problemset/problem/2108/C
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> dp;
    dp.push_back(-1);
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a != dp.back()) dp.push_back(a);
    }
    dp.push_back(-1);
    int ans = 0;
    for(int i=1;i<dp.size()-1;i++) {
        ans += dp[i-1] < dp[i] && dp[i] > dp[i+1];
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) solve();
}