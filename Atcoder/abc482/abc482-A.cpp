// Author : zhenzhe
// 2026/10/31 Sat 21:34:06
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    string str;
    cin >> str;
    int cnt = 0;
    for(auto &ch : str) cnt += ch == 'o';
    cout << (cnt & 1? "odd\n" : "even\n");
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
