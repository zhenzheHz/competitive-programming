// Problem : https://atcoder.jp/contests/abc402/tasks/abc402_d
// Tags : Math, Geometry
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        cnt[(a+b)%n]++;
    }
    int ans = m * (m-1) / 2;
    for(int i = 0; i < n; i++) {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
    return cout << ans, 0;
}