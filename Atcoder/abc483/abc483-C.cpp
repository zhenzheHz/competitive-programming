// Author : zhenzhe
// 2026/11/07 Sat 20:19:39
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
    vector<vector<int>> f(n);
    vector<int> cnt(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cnt[a]++;
        f[a].push_back(b);
    }

    set<pair<int, int>> t;
    for (int i = 0; i < n; i++) {
        t.insert({cnt[i], -i});
    }

    for (int i = 0; i < n; i++) {
        t.erase({cnt[i], -i});
        t.insert({-1, -i});
        for (auto s : f[i]) {
            t.erase({cnt[s], -s});
            cnt[s]++;
            t.insert({cnt[s], -s});
        }
        cout << -t.rbegin()->second + 1 << '\n';
        for (auto s : f[i]) {
            t.erase({cnt[s], -s});
            cnt[s]--;
            t.insert({cnt[s], -s});
        }
        t.erase({-1, -i});
        t.insert({cnt[i], -i});
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
