#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for(int &x : f) cin >> x;
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(f[i] - 2 * f[i+1] < 0) return cout << -1 << '\n', void();
        ans = max(ans, f[i] - 2* f[i+1]);
    }
    if(ans == 0 && f[0] > 0) ans = 1;
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
