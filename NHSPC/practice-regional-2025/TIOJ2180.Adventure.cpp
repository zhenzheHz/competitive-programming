// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2180
// Tag : 107北市賽
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
static constexpr int MAXN = 1005;
const pair<int,int> dxy[] = {{0,1},{0,-1},{1,0},{-1,0}};
int R,C,N,sx,sy,ex,ey,grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool inRange(int i,int j)  {
    return (i >=0 && i < R && j >= 0 && j < C);
}
bool check(int level) {
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.x == ex && cur.y == ey) return 1;
        for(auto [dx,dy] : dxy) {
            int tx = cur.x + dx, ty = cur.y + dy;
            if(!inRange(tx,ty) || grid[tx][ty] == -1) continue;
            if(vis[tx][ty] || grid[tx][ty] > level) continue;
            q.push({tx,ty});
            vis[tx][ty] = 1;
        }
    }
    return 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> R >> C;
    cin >> sx >> sy >> ex >> ey;
    cin >> N;
    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) grid[i][j] = -1;
    grid[sx][sy] = grid[ex][ey] = 0;
    int l = -1, r = 0;
    for(int i = 0; i < N; i++) {
        int x,y,lv;
        cin >> x >> y >> lv;
        grid[x][y] = lv;
        r = max(r, lv+1);
    }
    while(l+1 != r) {
        int mid = (l+r) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    return cout << r << '\n', 0;
}