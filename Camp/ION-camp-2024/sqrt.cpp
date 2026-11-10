#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
using namespace std;
using i64 = long long;

template <class T>
using vec = vector<T>;

constexpr int B = 2000;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vec<int> deg(n, 0);
    vec<pair<int, int>> color(n, pair{-1, 1}), op(n, pair{-1, -1});
    vec<vec<int>> G(n);
    for (int a, b; m--; ) {
        cin >> a >> b;
        --a, --b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        ++deg[a], ++deg[b];
    }
    {
        vec<vec<int>> adj(n);
        for (int i = 0; i < n; i++) for (auto to : G[i]) if (deg[i] < B || deg[to] >= B) adj[i].emplace_back(to);
        G = move(adj);
    }
    int q; cin >> q;
    for (int u, clr, i = 0; i < q; i++) {
        cin >> u >> clr;
        --u;
        if (deg[u] < B) for (auto to : G[u]) color[u] = max(color[u], op[to]);
        cout << color[u].second << '\n';
        color[u] = {i, clr};
        for (auto to : G[u]) color[to] = {i, clr};
        op[u] = {i, clr};
    }
}
