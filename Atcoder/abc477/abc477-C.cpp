// Author : zhenzhe
// 2026/09/26 Sat 20:10:56
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
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
    string S, T;
    int Q;
    cin >> Q >> S >> T;
    vector<int> match;
    for (int i = 0; i <= sz(S) - sz(T); i++) {
        if (S.substr(i, sz(T)) == T) {
            match.push_back(i);
        }
    }
    while (Q--) {
        int L, R;
        cin >> L >> R;
        --L, --R;
        int last = R - sz(T) + 1;
        auto it = lower_bound(match.begin(), match.end(), L);
        cout << (it != match.end() && *it <= last ? "Yes\n" : "No\n");
    }
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
