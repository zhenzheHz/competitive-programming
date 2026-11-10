// Author : zhenzhe
// 2026/10/26 Mon 23:02:05
#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
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
    int n, ans = 0;
    string s;
    cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> s;
        for (char c : s)
            ans += (c == 'f');
    }
    cout << ans % 2 << '\n';
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
