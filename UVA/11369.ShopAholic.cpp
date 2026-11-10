// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=d150
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for(int &i : prices) cin >> i;
        sort(prices.begin(),prices.end(),greater<int>());
        int save = 0;
        for(int i=2;i<n;i+=3) {
            save += prices[i];
        }
        cout << save << '\n';
    }
}