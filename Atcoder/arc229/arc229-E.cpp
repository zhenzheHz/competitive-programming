#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Edge {
    int u, v, l;
};

struct DSU {
    vector<int> pa;
    DSU(int n) : pa(n + 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) {
        if (pa[x] == x) return x;
        return pa[x] = find(pa[x]);
    }
    void merge(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) pa[root_i] = root_j;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    DSU dsu2(n), dsu3(n);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].l;
        if (edges[i].l == 2) dsu2.merge(edges[i].u, edges[i].v);
        if (edges[i].l == 3) dsu3.merge(edges[i].u, edges[i].v);
    }
    map<pair<int, int>, vector<int>> groups;
    for (int i = 1; i <= n; i++) {
        groups[{dsu2.find(i), dsu3.find(i)}].push_back(i);
    }
    int cnt = groups.size();
    vector<vector<int>> G(n + cnt + 1);
    for (auto& e : edges) {
        if (e.l == 1) {
            G[e.u].push_back(e.v);
            G[e.v].push_back(e.u);
        }
    }
    int id = n + 1;
    for (auto& [key, members] : groups) {
        for (int u : members) {
            G[u].push_back(id);
            G[id].push_back(u);
        }
        id++;
    }
    vector<bool> visited(n + cnt + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u <= n) {
            ans.push_back(u);
        }
        for (int v : G[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}