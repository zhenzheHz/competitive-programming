// Problem : https://codeforces.com/contest/1881/problem/F
// Tags : Greedy, Tree Diameter
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Graph = vector<vector<int>>;

void dfs(Graph &adj, vector<int> &depth, int cur, int from) {
    for(int nxt : adj[cur]) {
        if(nxt == from) continue;
        depth[nxt] = depth[cur] + 1;
        dfs(adj, depth, nxt, cur);
    }
}

void solve() {
    int n,k;
    cin >> n >> k;
    Graph g(n+1);
    vector<int> marked(k);
    for(int &x : marked) cin >> x;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(k == 1) return cout<<0<<'\n',void();
    vector<int> dis(n+1, 0);
    dfs(g, dis, marked[0], -1);
    int vertex = marked[0];
    for(int x : marked) {
        if(dis[x] > dis[vertex]) vertex = x;
    }
    for(int i=1;i<=n;i++) dis[i] = 0;
    dfs(g, dis, vertex, -1);
    for(int x : marked) {
        if(dis[x] > dis[vertex]) vertex = x;
    }
    return cout << (dis[vertex] + 1) / 2 << '\n',void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) solve();
}