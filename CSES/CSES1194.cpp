// Author : Zhenzhe
// Problem : https://cses.fi/problemset/task/1194/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int R,C,sx,sy;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
const string dir = "RLDU";
bool inRange(int x,int y) {
    return (x >= 0 && x < R && y >= 0 && y < C);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> R >> C;
    int grid[R][C], vis[R][C], vis2[R][C], prev[R][C];
    queue<pair<int,int>> q;
    memset(vis,-1,sizeof(vis));
    memset(vis2,-1,sizeof(vis2));
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            char c;
            cin >> c;
            if(c == 'A') sx = i, sy = j;
            else if(c == 'M') {
                q.push({i,j});
                grid[i][j] = 0;
                vis2[i][j] = 0;
            }
            else if(c == '#') grid[i][j] = -1;
            else grid[i][j] = 0;
        }
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int tx = cur.first + dx[i];
            int ty = cur.second + dy[i];
            if(!inRange(tx,ty)) continue;
            if(grid[tx][ty] == -1) continue;
            if(vis2[tx][ty] == -1) {
                vis2[tx][ty] = vis2[cur.first][cur.second] + 1;
                q.push({tx,ty});
            }
        }
    }
    q.push({sx,sy});
    vis[sx][sy] = 0;
    int ex = -1, ey = -1;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if(x == 0 || y == 0 || x == R-1 || y == C-1) {
            ex = x, ey = y;
            break;
        }
        for(int i=0;i<4;i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(!inRange(tx,ty) || grid[tx][ty] == -1) continue;
            if(vis[tx][ty] == -1 && (vis2[tx][ty] == -1 || vis[x][y] + 1 < vis2[tx][ty])) {
                vis[tx][ty] = vis[x][y] + 1;
                prev[tx][ty] = i;
                q.push({tx,ty});
            }
        }
    }
    if(ex == -1 && ey == -1) return cout << "NO\n",0;
    cout << "YES\n";
    cout << vis[ex][ey] << '\n';
    string path = "";
    int nx = ex, ny = ey;
    while(nx != sx || ny != sy) {
        // cout << nx << ' ' << ny << '\n';
        path.push_back(dir[prev[nx][ny]]);
        int k = prev[nx][ny];
        nx -= dx[k], ny -= dy[k];
    }
    reverse(path.begin(), path.end());
    return cout<<path,0;
}