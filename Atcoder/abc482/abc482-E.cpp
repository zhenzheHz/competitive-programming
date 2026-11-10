// Author : zhenzhe
// 2026/10/31 Sat 20:45:50
#include <bits/stdc++.h>
#include <slow>
#define int int64_t
using namespace std;

// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
static constexpr int MAXN = 2e5 + 5;

vector<int> G[MAXN];
vector<int> mark;

void dfs(const int cur, const int from, vector<int> &dist, vector<int> &pa) {
    for (const auto &nxt : G[cur]) {
        if (nxt == from) continue;
        dist[nxt] = dist[cur] + 1;
        pa[nxt] = cur;
        dfs(nxt, cur, dist, pa);
    }
}

void dfs2(const int cur, const int from, const int d, const int lim, vector<int> &cnt, vector<int> &ttd) {
    if (d == lim) {
        int x = mark[cur];
        if (cnt[x] == 0) ttd.push_back(x);
        cnt[x]++;
        return;
    }

    for (const auto &nxt : G[cur]) {
        if (nxt == from) continue;
        dfs2(nxt, cur, d + 1, lim, cnt, ttd);
    }
}

void solve() {
    int n;
    cin >> n;

    mark.resize(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (auto &x : mark) cin >> x;

    vector<int> dist(n, -1), pa(n, -1);

    dist[0] = 0;
    dfs(0, 0, dist, pa);

    int far = max_element(all(dist)) - dist.begin();

    fill(dist.begin(), dist.end(), -1);
    dist[far] = 0;
    dfs(far, far, dist, pa);

    int R = *max_element(all(dist));
    int tmp = max_element(all(dist)) - dist.begin();

    int target = (R & 1) ? (R + 1) / 2 : R / 2;

    while (dist[tmp] != target) {
        tmp = pa[tmp];
    }

    int ans = 0;

    if (R & 1) {
        int u = tmp, v = pa[tmp];
        vector<int> L(n+1), Rt(n+1), ttd;
        dfs2(u, v, 0, R / 2, L, ttd);
        dfs2(v, u, 0, R / 2, Rt, ttd);
        for (int i = 1; i <= n; i++) {
            ans += L[i] * Rt[i];
        }
    }
    else {
        int center = tmp;
        vector<int> total(n+1), cnt(n+1);
        for (const auto &v : G[center]) {
            vector<int> ttd;
            dfs2(v, center, 1, R / 2, cnt, ttd);
            for (const auto &x : ttd) {
                total[x] += cnt[x];
                ans -= cnt[x] * (cnt[x] - 1) / 2;
                cnt[x] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            ans += total[i] * (total[i] - 1) / 2;
        }
    }
    return cout << ans << '\n', void();
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