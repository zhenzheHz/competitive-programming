// Author : zhenzhe
// Time : 2026/09/19 20:02:31
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string str,cmp;
    cin >> str >> cmp;
    for(int i = 0; i < n; i++) {
        if(cmp[i] != '*' && str[i] != cmp[i]) {
            return cout << "No\n", void();
        }
        debug(cmp);
    }
    debug(str, cmp);
    return cout << "Yes\n", void();
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