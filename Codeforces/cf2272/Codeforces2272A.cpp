// Author : zhenzhe
// 2026/10/26 Mon 22:58:48
#include <bits/stdc++.h>
#define int int64_t
// #include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
using namespace std;
// using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

vector<int> get_pref_mex(const vector<int>& a) {
    int n = a.size();
    vector<int> f(n);
    set<int> missing;
    for (int i = 0; i <= n + 1; i++) missing.insert(i);
    
    for (int i = 0; i < n; i++) {
        missing.erase(a[i]);
        f[i] = *missing.begin();
    }
    return f;
}

void solve() {
    int n, k;
    cin >> n >> k;
    debug(n,k);
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> f = get_pref_mex(a);
    vector<int> sorted_f = f;
    sort(all(sorted_f));
    int best_val = sorted_f[n - k];
    int best_i = -1, best_j = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);
            vector<int> curr_f = get_pref_mex(a);
            sort(all(curr_f));
            int val = curr_f[n - k];
            
            if (val > best_val) {
                best_val = val;
                best_i = i + 1;
                best_j = j + 1;
            }
            swap(a[i], a[j]);
        }
    }
    if(best_i == -1) return cout << -1 << '\n', void();
    cout << best_i << ' ' << best_j << '\n';
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
