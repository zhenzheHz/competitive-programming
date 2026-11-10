// Problem : https://codeforces.com/problemset/problem/2009/E
// Tags : Ternary Search
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    const int sigma = (k + n + k - 1) * n / 2;
    function<int(int)> g=[&](int i) {
        int positive = (k + i) * (i-k+1) / 2;
        int negative = sigma - positive;
        return abs(positive - negative);
    };
    int l = k, r = n+k-1, ml, mr;
    while(r - l >= 3) {
        ml = l + (r-l)/3;
        mr = r - (r-l)/3;
        if(g(ml) <= g(mr)) r = mr;
        else l = ml;
    }
    int ans = 1e18;
    for(int i=l;i<=r;i++) {
        ans = min(ans, g(i));
    }
    return cout << ans << '\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }   
}