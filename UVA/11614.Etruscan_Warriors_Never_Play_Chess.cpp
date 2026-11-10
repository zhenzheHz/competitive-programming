// Author : Zhenzhe
// Time : 2024 / 11 / 06
// Problem : https://zerojudge.tw/ShowProblem?problemid=e658
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        int x;cin >> x;
        int l = 0, r = 1e10+1, m, check = x<<1;
        while(l+1!=r) {
            m = (l+r) >> 1;
            if(m*(m+1) <= check) l = m;
            else r = m;
        }
        cout << l << '\n';
    }
}