// Author : zhenzhe
// 2026/10/26 Mon 23:49:59
#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int long long
using namespace std;
// using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> f(n);
    for (auto &v : f) cin >> v;
    sort(f.begin(), f.end());

    auto check = [&](int k) -> bool {
        if (k == 0) return false;
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || f[i] - f[i-1] > k) && (i == n-1 || f[i+1] - f[i] > k)) {
                t.push_back(f[i]);
            }
        }
        int cnt = t.size();
        for (int i = 0; i + 1 < sz(t); ) {
            if (t[i+1] - t[i] <= 2 * k) {
                cnt--, i += 2;
            } else {
                i++;
            }
        }
        return cnt <= x;
    };

    int l = 0, r = max(1LL, f.back() - f.front());

    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }

    cout << r << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
