// Author : zhenzhe
// Time : 2026/09/19 20:14:37
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n,m,k,x,y;
    cin >> n >> m >> k >> x >> y;
    vector<int> f(n), ff(m), pref(n);
    for(int &x : f) cin >> x;
    for(int &x : ff) cin >> x;
    sort(all(f));
    sort(all(ff));
    pref[0] = f[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + f[i];
    }
    int ans = upper_bound(all(pref), x + k*y) - pref.begin();
    for(int i = 0, bill = 0, cost = 0, rest = x + k*y; i < m; i++) {
        int need = (ff[i] + k - 1) / k;
        if (bill + need > y) break;
        bill += need;
        cost += ff[i];
        rest = x + k * y - cost;
        int cnt = i + 1 + upper_bound(all(pref), rest) - pref.begin();
        chmax(ans, cnt);
    }
    return cout << ans, void();
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}