// Author : zhenzhe
// 2026/09/26 Sat 21:16:12
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

static constexpr int MAXN = 2e5 + 5;
static constexpr int LOGN = 19;

struct Query {
    int l, r, lca, id, a, b;
    int block;
    bool operator<(const Query &other) const {
        if (block != other.block) return block < other.block;
        return (block & 1) ? (r < other.r) : (r > other.r);
    }
};

int N, Q, _BCK, B_SIZE;
int x[MAXN];
vector<int> G[MAXN];
int up[MAXN][LOGN];
int depth[MAXN], in[MAXN], out[MAXN];
vector<int> dfn;

int cnt[MAXN];
int freq[MAXN];
int block_sum[MAXN];
bool vis[MAXN];

void dfs(int u, int p) {
    in[u] = dfn.size();
    dfn.push_back(u);
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    out[u] = dfn.size();
    dfn.push_back(u);
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void update(int u) {
    int val = x[u];
    freq[cnt[val]]--;
    block_sum[cnt[val] / _BCK]--;
    if (vis[u]) cnt[val]--;
    else cnt[val]++;
    vis[u] = !vis[u];
    freq[cnt[val]]++;
    block_sum[cnt[val] / _BCK]++;
}

int query_range(int l, int r) {
    if (l > r) return 0;
    chmax(l, (int)0);
    chmin(r, N);
    
    int sum = 0;
    int bl = l / _BCK, br = r / _BCK;
    if (bl == br) {
        for (int i = l; i <= r; i++) sum += freq[i];
    } else {
        for (int i = l; i < (bl + 1) * _BCK; i++) sum += freq[i];
        for (int i = bl + 1; i < br; i++) sum += block_sum[i];
        for (int i = br * _BCK; i <= r; i++) sum += freq[i];
    }
    return sum;
}

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> x[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfn.reserve(2 * N + 1);
    dfs(1, 0);
    B_SIZE = max((int)1, (int) (sz(dfn) / sqrt(Q)));
    _BCK = max((int)1, (int) sqrt(N + 1));

    vector<Query> Qs(Q);
    for (int i = 0; i < Q; i++) {
        int s, t, a, b;
        cin >> s >> t >> a >> b;
        if (in[s] > in[t]) swap(s, t);
        int lca = LCA(s, t);
        Qs[i].id = i;
        Qs[i].a = a;
        Qs[i].b = b;
        if (lca == s) {
            Qs[i].l = in[s];
            Qs[i].r = in[t];
            Qs[i].lca = 0;
        } else {
            Qs[i].l = out[s];
            Qs[i].r = in[t];
            Qs[i].lca = lca;
        }
        Qs[i].block = Qs[i].l / B_SIZE;
    }
    sort(all(Qs));

    freq[0] = N;
    block_sum[0] = N;

    int cur_l = 0, cur_r = -1;
    vector<int> ans(Q);

    for (auto &q : Qs) {
        while (cur_l > q.l) update(dfn[--cur_l]);
        while (cur_r < q.r) update(dfn[++cur_r]);
        while (cur_l < q.l) update(dfn[cur_l++]);
        while (cur_r > q.r) update(dfn[cur_r--]);

        if (q.lca) update(q.lca);
        ans[q.id] = query_range(q.a, q.b);
        if (q.lca) update(q.lca);
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;

    while (T--) {
        solve();
    }

    return 0;
}