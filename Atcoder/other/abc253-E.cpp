// Problem : https://atcoder.jp/contests/abc252/tasks/abc252_e
// Tags : Dijkstra, Shortest path tree
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, INF = 1e18;

struct Edge {
    int v,w;
    bool operator<(const Edge &cmp) const {
        return w > cmp.w;
    }
};

vector<pair<int,int>> G[MAXN];
vector<int> dist(MAXN, INF), pre(MAXN, -1);
map<pair<int,int>,int> edge_id;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        edge_id[{u,v}] = edge_id[{v,u}] = i+1;
    }
    priority_queue<Edge> pq;
    pq.push({1,0});
    dist[1] = 0, pre[1] = 1;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.v] < cur.w) continue;
        for(auto [nxt, w] : G[cur.v]) {
            if(dist[nxt] > dist[cur.v] + w) {
                dist[nxt] = dist[cur.v] + w;
                pq.push({nxt, dist[nxt]});
                pre[nxt] = cur.v;
            }
        }
    }
    for(int i = 2; i <= n; i++) {
        cout << edge_id[{i, pre[i]}] << " \n"[i==n];
    }
    return 0;
}