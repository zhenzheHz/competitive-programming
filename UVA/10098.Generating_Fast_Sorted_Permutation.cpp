// Author : Zhenzhe
// Time : 2024 / 11 / 07
// Problem : https://zerojudge.tw/ShowProblem?problemid=d436
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;string str;
    cin >> test;
    while(test--) {
        cin >> str;
        sort(str.begin(),str.end());
        do {
            cout << str << '\n';
        } while(next_permutation(str.begin(),str.end()));
        cout << '\n';
    }
}