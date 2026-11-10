// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2371
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 15,STN = 256, INF = 1e18;
const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
struct Point { int x,y,z,dir; };
#define id(i,j) (i*m+j)
char maze[MAXN][MAXN];
pair<int,int> rev[STN];
int n,m,b1,b2,b3,OUT,nxt[STN][4];
int dis[STN][STN][STN][4];
queue<Point> q;
int dfs(int x,int y,int d) {
    if(x < 0 || y < 0 || x >= n || y >= m) return OUT;
    if(maze[x][y] == 'w') return -1;
    if(nxt[id(x,y)][d] != -1) return nxt[id(x,y)][d];
    int result = dfs(x + dx[d], y + dy[d], d);
    if(result == -1) result = id(x,y);
    return nxt[id(x,y)][d] = result;
}   
int pre(int status, int d) {
    if(status >= OUT) return OUT;
    auto [x,y] = rev[status];
    d = (d + 2) % 4;
    int nx = x + dx[d], ny = y + dy[d];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return OUT;
    return id(nx, ny);
}
void relax(int x,int y,int z,int d,int distance) {
    auto simple_sort = [&]() {
        if(x > y) swap(x,y);
        if(y > z) swap(y,z);
        if(x > y) swap(x,y);
    };
    simple_sort();
    if(x >= 0 && y >= 0 && z >= 0) {
        if(x == y) {
            if(y == z) z = pre(pre(x,d),d);
            y = pre(x,d);
        }
        else if(y == z) {
            z = pre(y,d);
        }
        simple_sort();
        if(distance < dis[x][y][z][d]) {
            dis[x][y][z][d] = distance;
            q.push({x,y,z,d});
        }
    }
    
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    b1 = b2 = b3 = OUT = n*m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> maze[i][j];
            rev[id(i,j)] = {i,j};
            if(maze[i][j] == 'b') {
                if(b1 == OUT) b1 = id(i,j);
                else if(b2 == OUT) b2 = id(i,j);
                else b3 = id(i,j);
            }
            for(int k = 0; k < 4; k++) nxt[id(i,j)][k] = -1;
        }
    }
    for(int d = 0; d < 4; d++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i,j,d);
            }
        }
    }
    for(int d = 0; d < 4; d++) {
        nxt[OUT][d] = OUT;
        for(int i = 0; i < STN; i++) {
            for(int j = 0; j < STN; j++) {
                for(int k = 0; k < STN; k++) {
                    dis[i][j][k][d] = INF;
                }
            }
        }
    }
    dis[b1][b2][b3][0] = 0;
    q.push({b1,b2,b3,0});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int L = (cur.dir + 1) % 4, R = (cur.dir + 3) % 4;
        int dist = dis[cur.x][cur.y][cur.z][cur.dir] + 1;
        relax(nxt[cur.x][L],nxt[cur.y][L],nxt[cur.z][L],L,dist);
        relax(nxt[cur.x][R],nxt[cur.y][R],nxt[cur.z][R],R,dist);
    }
    int ans = *min_element(dis[OUT][OUT][OUT], dis[OUT][OUT][OUT]+4);
    return cout << (ans >= INF? -1 : ans) << '\n', 0;
}