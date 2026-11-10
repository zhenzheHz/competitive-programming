// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2224
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
vector<pair<int,int>> g[MAXN];
vector<int> degree(MAXN,0), dis(MAXN,LLONG_MAX);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        degree[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }
    dis[1] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto [nxt,w] : g[cur]) {
            if(--degree[nxt] == 0) {
                q.push(nxt);
            }
            dis[nxt] = min(dis[nxt],dis[cur]+w);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += dis[i];
    cout << ans << '\n';
    return 0;
}