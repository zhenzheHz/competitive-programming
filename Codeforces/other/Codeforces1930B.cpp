// Problem : https://codeforces.com/contest/1930/problem/B
// Tags : Math
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int left = 1, right = n;
        for(int i=1;i<=n;i++) {
            cout << (i&1? left++ : right--) << " \n"[i==n];
        }
    }
}