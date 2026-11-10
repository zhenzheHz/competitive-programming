// Problem : https://atcoder.jp/contests/abc401/tasks/abc401_f
// Tags : Tree Diameter, Binary Search, Prefix Sum
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
vector<int> d1(MAXN, 0), d2(MAXN, 0);
vector<vector<int>> G1(MAXN), G2(MAXN);

int bfs(vector<vector<int>> &G, vector<int> &dist, int N, int start) {
    dist.assign(N+1,-1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int far = start;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(dist[cur] > dist[far]) far = cur;
        for(auto nxt : G[cur]) {
            if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return far;
}

int diameter(vector<vector<int>> &G, vector<int> &d, int N) {
    vector<int> distA(N+1), distB(N+1);
    int A = bfs(G, distA, N, 1);
    int B = bfs(G, distA, N, A);
    A = bfs(G, distB, N, B);
    d.resize(N+1);
    for(int i = 1; i <= N; i++) {
        d[i] = max(distA[i], distB[i]);
    }
    return distB[A];
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    cin >> m;
    for(int i = 1; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    int DM1 = diameter(G1, d1, n), DM2 = diameter(G2, d2, m);
    sort(d2.begin()+1, d2.begin()+m+1);
    vector<int> pref(m+1, 0);
    for(int i = 1; i <= m; i++) {
        pref[i] = pref[i-1] + d2[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        auto f = lower_bound(d2.begin()+1, d2.begin()+m+1, max(DM1,DM2)-d1[i]-1);
        int x = f - d2.begin() - 1;
        ans += x * max(DM1, DM2);
        ans += (m-x) * (d1[i] + 1) + pref[m] - pref[x];
    }
    return cout << ans, 0;
}