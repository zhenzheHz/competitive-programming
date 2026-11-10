// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=e523
// Tag : 106學年度 彰雲嘉複賽 資訊學科能力 3
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    vector<int> F = {0,1};
    while(F[F.size()-1] + F[F.size()-2] <= 1000000) {
        F.push_back(F[F.size()-1] + F[F.size()-2]);
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        auto f = lower_bound(F.begin(), F.end(), x);
        cout << (*f == x? f - F.begin() : -1) << '\n';
    }
    return 0;
}