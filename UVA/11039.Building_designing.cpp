// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=d731
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int SIZE;
    cin >> SIZE;
    vector<int> Array(SIZE+1),dp(SIZE+1,0);
    Array[0] = 0;
    for(int i=1;i<=SIZE;i++) cin >> Array[i];
    sort(Array.begin()+1,Array.end(),[&](const int &a,const int &b){
        return abs(a) < abs(b);
    });
    int pos = 0, neg = 0;
    for(int i=1;i<=SIZE;i++) {
        if(Array[i] > 0) {
            dp[i] = max(dp[neg] + 1,(int64_t) 1);
            pos = i;
        }else {
            dp[i] = max(dp[pos] + 1,(int64_t) 1);
            neg = i;
        }
    }
    cout << *max_element(dp.begin()+1,dp.end()) << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}