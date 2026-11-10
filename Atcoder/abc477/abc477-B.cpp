// Author : zhenzhe
// 2026/09/26 Sat 20:03:55
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
    int n,D;
    cin >> n >> D;
    vector<int> f(n), ans;
    for(auto &i : f) cin >> i;
    for(int i = 0; i < n; i++) {
        bool valid = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(abs(f[i] - f[j]) < D) {
                valid = 0;
                break;
            }
        }
        if(valid) ans.push_back(i+1);
    }
    cout << ans.size() << '\n';
    for(auto &x : ans) cout << x << ' ';
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
