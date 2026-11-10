// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c124
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Point {int x,y,z;};
const Point dxyz[] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
#define inside(i,j,k) (i >= 0 && i < R && j >= 0 && j < C && k >=0 && k < L)
void solve(int R,int C,int L) {
    int valid[R][C][L], dis[R][C][L];
    Point st,ed;
    for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) {
        for(int k = 0; k < L; k++) {
            char c;
            cin >> c;
            if(c == 'S') st = {i,j,k}, valid[i][j][k] = 1;
            else if(c == 'E') ed = {i,j,k}, valid[i][j][k] = 1;
            else valid[i][j][k] = (c == '.');
            dis[i][j][k] = -1;
        }
    }
    queue<Point> q;
    q.push(st);
    dis[st.x][st.y][st.z] = 0;
    while(!q.empty()) {
        auto [x,y,z] = q.front();
        q.pop();
        for(auto [dx,dy,dz] : dxyz) {
            int tx = x + dx, ty = y + dy, tz = z + dz;
            if(!inside(tx,ty,tz) || !valid[tx][ty][tz]) continue;
            if(dis[tx][ty][tz] >= 0) continue;
            dis[tx][ty][tz] = dis[x][y][z] + 1;
            q.push({tx,ty,tz});
        }
    }
    if(dis[ed.x][ed.y][ed.z] <= 0) cout << "Trapped!\n";
    else cout << "Escaped in " << dis[ed.x][ed.y][ed.z] << " minute(s).\n"; 
    return;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int R,C,L;
    while(cin >> R >> C >> L) {
        if(R == 0 && C == 0 && L == 0) break;
        solve(R,C,L);
    }
    return 0;
}