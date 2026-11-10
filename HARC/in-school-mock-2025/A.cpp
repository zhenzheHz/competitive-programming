#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5,INF=1e18;
struct Edge {
    int v,w,s;
    bool operator<(const Edge &cmp) const {
        return w > cmp.w;
    }
};
vector<Edge> g[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,start,end,alpha;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b,x,s;
        cin >> a >> b >> x >> s;
        g[a].push_back({b,x,s});
    }
    cin >> start >> end >> alpha;
    for(int i=1;i<=n;i++) {
        for(auto &ed : g[i]) {
            if(ed.s) ed.w -= alpha;
        }
    }
    priority_queue<Edge> pq;
    pq.push({start,0,0});
    vector<int> dis(MAXN,INF);
    dis[start] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(cur.w > dis[cur.v]) continue;
        for(auto edge : g[cur.v]) {
            if(dis[edge.v] > dis[cur.v] + edge.w) {
                dis[edge.v] = dis[cur.v] + edge.w;
                pq.push({edge.v,dis[edge.v],0});
            }
        }
    }
    cout << (dis[end] >= INF? -1 : dis[end]);
    return 0;
}