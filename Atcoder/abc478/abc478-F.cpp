// Author : zhenzhe
// 2026/10/03 Sat 21:30:23
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
static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

vector<int> prev_greater(const vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] <= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            ans[i] = stk.top();
        }
        stk.push(i);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> f(n);
    for(auto &x : f) cin >> x;
    vector<int> mark = prev_greater(f);
    int ans = 1;
    for(int i = 1; i < n; i++) {
        int tmp = (mark[i] == -1? i : i - mark[i]);
        ans = (ans * tmp) % MOD; 
    }
    return cout << ans, void();
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
