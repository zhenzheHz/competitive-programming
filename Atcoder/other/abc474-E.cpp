// Problem : https://atcoder.jp/contests/abc474/tasks/abc474_e
// Tags : Prefix sum, greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> diff(n+1, 0), pref(n+1, 0);
    int total = 0, coupon = 1e18;
    for(int i = 1; i <= n; i++) {
        int a,b;
        cin >> a >> b;
        diff[i] = a-b;
        coupon = min(coupon, a);
        total += b;
    }
    sort(diff.begin()+1, diff.end());
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + diff[i];
    }
    int ans = 1e18;
    for(int k = 0; k <= n; k++) {
        int cost = total + pref[k] + max((int) 0, n-2*k) * coupon;
        ans = min(ans, cost);
    }
    return cout << ans << '\n', void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}