// Author : Zhenzhe
// Problem : https://mysh212.github.io/CHSH-nhspc114-PRI
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, INF = 1e18, LOGN = 18;
struct Edge {
    int u,v,w;
    bool operator<(const Edge &cmp) const {
        return w > cmp.w;
    }
};
struct Dsu {
    int pa[MAXN];
    void init() { iota(pa,pa+MAXN,0); }
    int find(int x) { return (x == pa[x]? pa[x] : pa[x] = find(pa[x])); }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        return pa[a] = b, 1;
    }
};
vector<Edge> G[MAXN], KTree[MAXN],lst;
int dis[MAXN], depth[MAXN], dp[MAXN][LOGN], max_dis[MAXN][LOGN];
Dsu dsu;
void dfs(int cur, int from) {
    depth[cur] = depth[from] + 1;
    for(int j = 1; j < LOGN; j++) {
        dp[cur][j] = dp[dp[cur][j-1]][j-1];
        max_dis[cur][j] = max(max_dis[cur][j-1], max_dis[dp[cur][j-1]][j-1]);
    }
    for(auto [u,nxt,w] : KTree[cur]) {
        if(nxt == from) continue;
        dp[nxt][0] = cur;
        max_dis[nxt][0] = w;
        dfs(nxt,cur);
    }
}
int findLCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b], power = 0, tmp = 0;
    while(diff) {
        if(diff & 1) {
            tmp = max(tmp, max_dis[a][power]);
            a = dp[a][power];
        }
        diff >>= 1, power++;
    }
    if(a == b) return tmp;
    for(int j = LOGN-1; j >= 0; j--) {
        if(dp[a][j] == dp[b][j]) continue;
        tmp = max({tmp, max_dis[a][j], max_dis[b][j]});
        a = dp[a][j], b = dp[b][j];
    }
    return max({tmp, max_dis[a][0], max_dis[b][0]});
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    fill(dis, dis+MAXN, INF);
    int N,M,K,Q,u,v,w;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        G[u].push_back({u,v,w});
        G[v].push_back({v,u,w});
        lst.push_back({u,v,w});
    }
    priority_queue<Edge> pq;
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> u;
        pq.push({u,u,0});
        dis[u] = 0;
    }
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(cur.w > dis[cur.v]) continue;
        for(auto [u,nxt,w] : G[cur.u]) {
            if(dis[cur.v] + w < dis[nxt]) {
                dis[nxt] = dis[cur.v] + w;
                pq.push({nxt,nxt,dis[nxt]});
            }
        }
    }
    for(auto &[u,v,w] : lst) {
        w = max(dis[u],dis[v]);
    }
    sort(lst.rbegin(), lst.rend());
    dsu.init();
    for(auto [u,v,w] : lst) {
        if(dsu.merge(u,v)) {
            KTree[u].push_back({u,v,w});
            KTree[v].push_back({v,u,w});
        }
    }
    dfs(1,1);
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int s,t;
        cin >> s >> t;
        if(s == t) cout << dis[s];
        else cout << findLCA(s,t);
        cout << '\n';
    }
    return 0;
}