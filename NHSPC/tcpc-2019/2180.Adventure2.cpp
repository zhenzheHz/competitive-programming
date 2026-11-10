// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2018 北市賽 
// Tags : Dijkstra(圖論)
// Problem : https://tioj.ck.tp.edu.tw/problems/2180
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Node {
    int x, y, level = 0;
    bool operator<(const Node &cmp) const {
        return level > cmp.level;
    }
};
int R,C,N,g[1005][1005],dp[1005][1005];
pair<int,int> nxt[] = {{0,1},{0,-1},{1,0},{-1,0}};
Node st, ed;

#define inRange(i,j) (i>=0 && i<R && j>=0 && j<C)
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    memset(g,-1,sizeof(g));
    // memset(vis,0,sizeof(vis));
    cin >> R >> C;
    cin >> st.x >> st.y;
    cin >> ed.x >> ed.y;
    cin >> N;
    while(N--) {
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    priority_queue<Node> pq;
    pq.push({st.x,st.y,0});
    g[st.x][st.y] = g[ed.x][ed.y] = 0;
    dp[st.x][st.y] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        for(auto dir : nxt) {
            int tx = cur.x + dir.first;
            int ty = cur.y + dir.second;
            if(!inRange(tx,ty) || g[tx][ty] == -1) continue;
            if (max(dp[cur.x][cur.y], g[tx][ty]) < dp[tx][ty]) {
                dp[tx][ty] = max(dp[cur.x][cur.y], g[tx][ty]);
                pq.push({tx, ty, dp[tx][ty]});
            }
        }
    }
    cout << dp[ed.x][ed.y] << '\n';
}