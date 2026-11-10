// Author : zhenzhe
// 2026/10/11 Sun 20:48:53
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
static constexpr int MAXN = 2e5 + 5;

vector<int> G[MAXN], cnt(MAXN, 1);

vector<int> _in(MAXN), _out(MAXN) ,dfn(MAXN);

static int timer = 0;

void dfs(int cur, int from) {
    _in[cur] = ++timer;
    dfn[timer] = cur;
    for(auto &nxt : G[cur]) {
        if(nxt == from) continue;
        dfs(nxt, cur);
        cnt[cur] += cnt[nxt];
    }
    _out[cur] = timer;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> edges(n-1);
    for(auto &[u,v] : edges) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    vector<int> diff(MAXN, 0);
    for(int i = 1; i < n; i++) {
        auto [u,v] = edges[i-1];
        if(cnt[u] < cnt[v]) swap(u,v);
        if(cnt[v] > (n>>1)) {
            diff[_in[v]] += i;
            diff[_out[v]+1] -= i;
        }
        else {
            diff[1] += i;
            diff[_in[v]] -= i;
            diff[_out[v]+1] += i;
            diff[n+1] -= i;
        }
    }

    diff[0] = 0;

    vector<int> ans(MAXN, 0);

    for(int i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
        ans[dfn[i]] = diff[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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
