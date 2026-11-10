// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=i959
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,p;
    cin >> n >> p;
    set<int> Maximum, current;
    current.insert(p);
    for(int i=1;i<n;i++) {
        cin >> p;
        Maximum.insert(*current.rbegin() - p);
        current.insert(p);
    }
    cout << *Maximum.rbegin() << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}