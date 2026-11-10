// Problem : https://codeforces.com/problemset/problem/676/D
// Tags : BFS
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
static constexpr int INF = 1e18;
struct state {
    int x,y,rotate = 0;
};
vector<int> getDoors(char c) {
    switch(c) {
        case '+': return {0,1,2,3};
        case '-': return {1,3};
        case '|': return {0,2};
        case '^': return {0};
        case '>': return {1};
        case 'v': return {2};
        case '<': return {3};
        case 'L': return {0,1,2};
        case 'R': return {0,2,3};
        case 'U': return {1,2,3};
        case 'D': return {0,1,3};
        default: return {};
    }
}
bool haveDoor(char c, int rot, int dir) {
    vector<int> doors = getDoors(c);
    for(int &door : doors) {
        if((door + rot) % 4 == dir) return 1;
    }
    return 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int row,col;
    state start, end;
    cin >> row >> col;
    char g[row+1][col+1];
    int dis[row+1][col+1][4];
    for(int i=1;i<=row;i++) for(int j=1;j<=col;j++) {
        cin >> g[i][j];
        for(int k=0;k<4;k++) dis[i][j][k] = INF;
    }
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;

    #define inRange(i,j) (i>0&&i<=row&&j>0&&j<=col)

    queue<state> bfs;
    bfs.push({start.x,start.y,0});
    dis[start.x][start.y][0] = 0;
    while(!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        int dist = dis[cur.x][cur.y][cur.rotate];
        if(dist + 1 < dis[cur.x][cur.y][(cur.rotate + 1) % 4]) {
            dis[cur.x][cur.y][(cur.rotate + 1) % 4] = dist + 1;
            bfs.push({cur.x,cur.y,(cur.rotate + 1) % 4});
        }
        for(int nxt = 0; nxt < 4; nxt++) {
            if(!haveDoor(g[cur.x][cur.y],cur.rotate,nxt)) continue;
            int tx = cur.x + dx[nxt], ty = cur.y + dy[nxt];
            if(!inRange(tx,ty) || g[tx][ty] == '*') continue;
            if(!haveDoor(g[tx][ty],cur.rotate,(nxt + 2) % 4)) continue;
            if(dist + 1 < dis[tx][ty][cur.rotate]) {
                dis[tx][ty][cur.rotate] = dist + 1;
                bfs.push({tx,ty,cur.rotate});
            }
        }
    }
    int ans = INF;
    for(int i=0;i<4;i++) ans = min(ans,dis[end.x][end.y][i]);
    return cout << (ans == INF ? -1 : ans) << "\n",0;
}