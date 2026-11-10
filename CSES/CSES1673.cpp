// Problem : https://cses.fi/problemset/task/1673/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Edge {int u,v,w;};
void dfs(vector<vector<int>> &G, vector<int> &vis, int cur) {
    if(vis[cur]) return;
    vis[cur] = 1;
    for(auto nxt : G[cur]) {
        dfs(G,vis,nxt);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1),rg(n+1);
    vector<Edge> lst(m);
    for(int i=0;i<m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        lst[i] = {a,b,(-1)*x};
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    vector<int> dis(n+1,(int)1e18);
    dis[1] = 0;
    for(int i=1;i<n;i++) {
        for(auto edge : lst) {
            dis[edge.v] = min(dis[edge.u] + edge.w,dis[edge.v]);
        }
    }
    vector<int> vis(n+1,0), rvis(n+1,0);
    dfs(g,vis,1);
    dfs(rg,rvis,n);
    for(auto edge : lst) {
        if(dis[edge.u] + edge.w < dis[edge.v]) {
            if(vis[edge.u] && rvis[edge.v]) {
                return cout<<-1,0;
            }
        }
    }
    return cout<<-1*dis[n],0;
}