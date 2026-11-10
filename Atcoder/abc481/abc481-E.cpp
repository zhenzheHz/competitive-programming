// Author : zhenzhe
// 2026/10/24 Sat 20:42:59
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
// #include <slow>
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
static const double PI = acos(-1);

using Point = pair<int,int>;
#define x first
#define y second

bool check(const Point &p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}

inline int cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> f(n);
    for(auto &[x,y] : f) cin >> x >> y;
    sort(all(f), [&](const auto &a, const auto &b) {
        if(check(a) != check(b)) return check(a) > check(b);
        return cross(a,b) > 0;
    });
    for(int i = 0; i < n; i++) {
        f.push_back(f[i]);        
    }
    int ans = 0, j = 1;
    for(int i = 0; i < n; i++) {
        if(j <= i) j = i+1;
        while(j < i+n && cross(f[i], f[j]) > 0) j++;
        chmax(ans, j-i);
    }
    return cout << ans << '\n', void();
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
