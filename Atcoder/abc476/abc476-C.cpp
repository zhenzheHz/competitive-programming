// Author : zhenzhe
// Time : 2026/09/19 20:07:15
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

void solve() {
    int n;
    cin >> n;
    // vector<int> f(n);
    multiset<int> ms;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
        if(ms.size() > 3) ms.erase(ms.begin());
        if(ms.size() >= 3) cout << *ms.begin() << '\n';
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