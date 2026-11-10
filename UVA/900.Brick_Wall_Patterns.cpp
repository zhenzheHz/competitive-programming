// Author : Zhenzhe
// Time : 2024 / 10 / 18
// Problem : https://zerojudge.tw/ShowProblem?problemid=d038
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int64_t dp[52];
    dp[1] = 1, dp[2] = 2;
    for(int i = 3;i<52;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int test;
    while(cin >> test) {
        if(!test) break;
        cout << dp[test] << '\n';
    }
}