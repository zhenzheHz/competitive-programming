// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=a993
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    while(cin >> test) {
        int number = 1, term = 1;
        while(number % test) {
            number = number * 10 + 1;
            number %= test;
            term += 1;
        }
        cout << term << '\n';
    }
}