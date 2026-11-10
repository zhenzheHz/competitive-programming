// Author : zhenzhe
// 2026/11/07 Sat 21:02:28
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    unordered_map<string, int> freq;
    int p0 = 0;
    for (auto &x : s) {
        cin >> x;
        p0 += freq[x]++;
    }
    int a = 0, b = 0;
    for (int i = 0; i < m; i++) {
        unordered_map<string, int> cnt;
        for (auto &str : s) {
            string key;
            for (int k = 0; k < m; k++) {
                if (k != i) key += str[k];
            }
            a += cnt[key]++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            unordered_map<string, int> cnt;
            for (auto &str : s) {
                string key;
                for (int k = 0; k < m; k++) {
                    if (k != i && k != j) key += str[k];
                }
                b += cnt[key]++;
            }
        }
    }

    int p1 = a - m * p0;
    int p2 = b - m * (m - 1) / 2 * p0 - (m - 1) * p1;
    cout << p0 + p1 + p2 << '\n';
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
