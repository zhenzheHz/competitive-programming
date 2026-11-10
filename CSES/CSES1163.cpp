// Problem : https://cses.fi/problemset/task/1163
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x,n;
    cin >> x >> n;
    multiset<int> break_point = {0,x}, len = {x};
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        auto right = break_point.upper_bound(k);
        auto left = prev(right);
        int origin = *right - *left;
        break_point.insert(k);
        len.insert(k - *left);
        len.insert(*right - k);
        len.erase(len.find(origin));
        cout << *len.rbegin() << ' ';
    }
    return 0;
}