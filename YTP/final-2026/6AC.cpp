#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;

struct Edge {
    int u,v,w;
    bool operator<(const Edge &cmp) const {
        return w < cmp.w;
    }
};

int n,m,k,dist[MAXN];
vector<Edge> G[MAXN],lst;

bool check(int max_w) {
    for(int i = 0; i < MAXN; i++) {
        G[i].clear();
        dist[i] = (int) 1e18;
    }
    for(auto [u,v,w] : lst) {
        G[u].push_back({u, v, w > max_w});
        G[v].push_back({v, u, w > max_w});
    }
    deque<int> dq;
    dq.push_back(1);
    dist[1] = 0;
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto &[u, v, cost] : G[u]) {
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                if (cost == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist[n] <= k;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        lst.push_back({u,v,w});
    }
    sort(lst.begin(), lst.end());
    int l = -1, r = lst.size();
    while(l+1 != r) {
        int mid = (l+r) >> 1;
        if(check(lst[mid].w)) r = mid;
        else l = mid;
    }
    cout << (lst[r].w == 0? -1 : lst[r].w);
}