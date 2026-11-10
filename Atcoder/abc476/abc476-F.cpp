// Author : zhenzhe
// Time : 2026/09/19 21:20:56
// Note : TLE
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

int get(const vector<vector<int>> &pref, int n, int r1, int c1, int r2, int c2) {
    r1 = max<int>(1, r1);
    c1 = max<int>(1, c1);
    r2 = min<int>(n, r2);
    c2 = min<int>(n, c2);
    if (r1 > r2 || c1 > c2) return 0;
    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w = (a[i] * b[j]) % m;
            pref[i][j] = w + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int maxDist = max({i - 1, n - i, j - 1, n - j});
            int tmp = 0;
            int prevSum = get(pref, n, i, j, i, j);
            for (int d = 1; d <= maxDist; d++) {
                int curSum = get(pref, n, i - d, j - d, i + d, j + d);
                tmp += d * (curSum - prevSum);
                prevSum = curSum;
            }
            int v = tmp + (i - 1) * n + (j - 1);
            ans ^= v;
        }
    }

    cout << ans << "\n";
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