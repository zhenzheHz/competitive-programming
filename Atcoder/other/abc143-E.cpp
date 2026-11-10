// Problem : https://atcoder.jp/contests/abc143/tasks/abc143_e
// Tags : Floyd Warshall
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 305, INF = 1e18;
int n,m,L,Q,dist[MAXN][MAXN],ans[MAXN][MAXN];

inline bool chmin(int &a, int b) {
    return (a > b? a = b, 1 : 0);
} 

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m >> L;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = ans[i][j] = INF;
        }
        dist[i][i] = ans[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && dist[i][j] <= L) 
                chmin(ans[i][j], 1);
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                chmin(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int s,t;
        cin >> s >> t;
        cout << (ans[s][t] >= INF? -1 : ans[s][t] - 1) << '\n';
    }
    return 0;
}