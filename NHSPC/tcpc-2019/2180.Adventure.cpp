// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2018 北市賽 
// Tags : 二分搜 + BFS(圖論)
// Problem : https://tioj.ck.tp.edu.tw/problems/2180
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
static constexpr int MAXN = 1005;
int R,C,N,g[MAXN][MAXN];
pair<int,int> start, des,nxt[] = {{1,0},{-1,0},{0,1},{0,-1}};

#define inRange(i,j) (i>=0 && i<R && j>=0 && j<C)
bool check(int level) {
    queue<pair<int,int>> run;
    bool vis[MAXN][MAXN];
    memset(vis,0,sizeof(vis));
    run.push(start);
    vis[start.x][start.y] = 1;
    while(!run.empty()) {
        auto cur = run.front();
        run.pop();
        if(cur == des) return 1;
        // vis[cur.x][cur.y] = 1;
        for(auto dir : nxt) {
            int tx = cur.x + dir.x;
            int ty = cur.y + dir.y;
            if(!inRange(tx,ty) || vis[tx][ty] || g[tx][ty] > level) continue;
            if(g[tx][ty] == -1) continue;
            run.push({tx,ty});
            vis[tx][ty] = 1;
        }
        // if(vis[des.x][des.y]) break;
    }
    return 0;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    memset(g,-1,sizeof(g));
    cin >> R >> C;
    cin >> start.x >> start.y;
    cin >> des.x >> des.y;
    cin >> N;
    g[start.x][start.y] = g[des.x][des.y] = 0;
    int l = 0, r = 0;
    while(N--) {
        int a,b,m;
        cin >> a >> b >> m;
        g[a][b] = m;
        r = max(r, m+1);
    }
    while(l+1 != r) {
        int m = (l+r) >> 1;
        if(check(m)) r = m;
        else l = m;
    }
    cout << r << '\n';
}