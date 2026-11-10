// Author : zhenzhe
// 2026/09/26 Sat
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
    int n, q;
    cin >> n >> q;
    
    vector<char> ans(n+1, 'a');
    vector<int> no(n+1, 0);
    vector<int> last_op2(q+1, 0);
    vector<char> color(q+1, 'a');

    for (int t = 1; t <= q; t++) {
        int type;
        cin >> type;
        last_op2[t] = last_op2[t - 1]; 

        if (type == 1) {
            int x;
            cin >> x;
            if (no[x] != -1) {
                int last_time = last_op2[t - 1];
                if (last_time >= no[x] && last_time != 0) {
                    ans[x] = color[last_time];
                }
                no[x] = -1;
            } else {
                no[x] = t;
            }
        } else {
            char c;
            cin >> c;
            last_op2[t] = t;
            color[t] = c;
        }
    }

    for (int x = 1; x <= n; x++) {
        if (no[x] != -1) {
            int last_time = last_op2[q];
            if (last_time >= no[x] && last_time != 0) {
                ans[x] = color[last_time];
            }
        }
        cout << ans[x];
    }
    cout << "\n";
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T = 1;
    while (T--) solve();
    return 0;
}