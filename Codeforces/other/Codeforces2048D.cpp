// Problem : https://codeforces.com/contest/2048/problem/D
// Tags : Greedy, Binary Search
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m), rk(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    int rate = a[0];
    sort(a.begin(), a.end());
    for(int i=0;i<m;i++) {
        auto f = lower_bound(a.begin(), a.end(), b[i]);
        rk[i] = (rate >= b[i]? 1 : n - (f - a.begin()) + 1);
    }
    sort(rk.begin(), rk.end());
    for(int k=1;k<=m;k++) {
        int ans = 0;
        for(int i=k-1;i<m;i+=k) {
            ans += rk[i];
        }
        cout << ans << " \n"[k==m];
    }
    return void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}