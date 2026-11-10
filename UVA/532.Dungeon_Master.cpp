// Author : Zhenzhe
// Time : 2024 / 11 / 13
// Problem : https://zerojudge.tw/ShowProblem?problemid=c124
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct point {int x,y,z;};
point dir[] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
void solve(int r,int c,int l) {
    point start, end;
    char g[r][c][l];
    int dis[r][c][l];
    memset(dis,-1,sizeof(dis));
    for(int k=0;k<l;k++) for(int i=0;i<r;i++)
        for(int j=0;j<c;j++) {
            cin >> g[i][j][k];
            if(g[i][j][k] == 'S') start = {i,j,k};
            if(g[i][j][k] == 'E') end = {i,j,k};
            if(g[i][j][k] == '#') dis[i][j][k] = 0;
            else if(dis[i][j][k] == '.') dis[i][j][k] = -1;
        }
    queue<point> bfs;
    bfs.push(start);
    dis[start.x][start.y][start.z] = 1;
    #define inRange(i,j,k) (i>=0&&i<r&&j>=0&&j<c&&k>=0&&k<l)
    while(!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        for(int cc = 0; cc < 6; cc++) {
            int tx = cur.x + dir[cc].x;
            int ty = cur.y + dir[cc].y;
            int tz = cur.z + dir[cc].z;
            if(inRange(tx,ty,tz) && dis[tx][ty][tz] == -1) {
                dis[tx][ty][tz] = dis[cur.x][cur.y][cur.z] + 1;
                bfs.push({tx,ty,tz});
            } 
        }
    }
    if(dis[end.x][end.y][end.z] != -1) cout << "Escaped in " << dis[end.x][end.y][end.z]-1 << " minute(s).\n";
    else cout << "Trapped!\n";
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int r,c,l;
    while(cin >> l >> r >> c) {
        if(r == 0 && c == 0 && l == 0) break;
        solve(r,c,l);
    }
}