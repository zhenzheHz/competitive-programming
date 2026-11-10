// Problem : https://codeforces.com/contest/2009/problem/E
// Tags : Binary Search
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    const int sigma = (k + n + k - 1) * n / 2;
    function<int(int)> check=[&](int i) {
        int positive = (k + i) * (i-k+1) / 2;
        int negative = sigma - positive;
        return positive - negative;
    };
    int l = k-1, r = n+k;
    while(l+1!=r) {
        int m = (l+r)>>1;
        if(check(m) >= 0) r = m;
        else l = m;
    }
    int ans = min(abs(check(r)),abs(check(r-1)));
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }   
}