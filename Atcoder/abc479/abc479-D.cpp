// Author : zhenzhe
// 2026/10/11 Sun 20:21:06
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
static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> L(n+1, INF), R(n+1, INF);
    for(int i = 2; i <= n; i++) {
        cin >> L[i];
    }

    for(int i = 1; i < n; i++) {
        cin >> R[i];
    }

    vector<int> prefR(n + 2, INF);
    for(int i = 1; i <= n; i++) {
        prefR[i] = min(prefR[i-1], R[i]);
    }

    vector<int> suffL(n + 2, INF);
    for(int i = n; i >= 1; i--) {
        suffL[i] = min(suffL[i+1], L[i]);
    }

    while(q--) {
        int s, t;
        cin >> s >> t;
        if (s == t) {
            cout << 0 << "\n";
            continue;
        }

        int ans = (s < t ? R[s] : L[s]);

        int mmin = min(s, t), mmax = max(s, t);
        if (mmin > 1) {
            chmin(ans, L[s] + prefR[mmin-1]);
        }
        if (mmax < n) {
            chmin(ans, R[s] + suffL[mmax+1]);
        }

        cout << ans << '\n';
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
