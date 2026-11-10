// Author : Zhenzhe
// Time : 2024 / 10 / 17
// Problem : https://zerojudge.tw/ShowProblem?problemid=d253
#include <bits/stdc++.h>
using namespace std;
static constexpr int MAXN = 7500;
vector<int64_t> coins = {1,5,10,25,50};
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int64_t dp[MAXN];
    memset(dp,0LL,sizeof(dp));
    dp[0] = 1;
    for(int64_t coin : coins) {
        for(int64_t j = 0; j+coin<MAXN; j++) {
            dp[j+coin] += dp[j];
        }
    }
    int test;
    while(cin >> test) {
        cout << dp[test] << '\n';
    }
}