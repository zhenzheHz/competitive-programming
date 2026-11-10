// Author : Zhenzhe
// Time : 2024 / 10 / 17
// Problem : https://zerojudge.tw/ShowProblem?problemid=a249
#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}
void solve() {
    int depth, order, position = 1;
    cin >> depth >> order;
    order -= 1;
    for(int i=1;i<depth;i++) {
        position = position << 1 | (order & 1);
        order >>= 1;
    }
    cout << position << '\n';
}