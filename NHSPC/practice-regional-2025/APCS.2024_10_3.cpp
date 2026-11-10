// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=o713
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
static constexpr int MAXN = 505;
const pair<int,int> dxy[] = {{1,0},{-1,0},{0,1},{0,-1}};
int N,M,q;
pair<int,int> st;
int32_t grid[MAXN][MAXN], vis[MAXN][MAXN];
bool done[MAXN][MAXN];
bool inside(int i,int j) {
    return (i >=0 && i < N && j >= 0 && j < M);
}
void explode(int sx, int sy) {
    done[sx][sy] = 1;
    queue<pair<int,int>> q;
    vector<pair<int,int>> trigger;
    q.push({sx,sy});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(grid[cur.x][cur.y] > 0 && !done[cur.x][cur.y]) {
            trigger.push_back(cur);
        }
        if(vis[cur.x][cur.y] == 0) continue;
        for(auto [dx,dy] : dxy) {
            int tx = cur.x + dx, ty = cur.y + dy;
            if(!inside(tx,ty) || grid[tx][ty] == -1) continue;
            if(vis[cur.x][cur.y] - 1 <= vis[tx][ty]) continue;
            q.push({tx,ty});
            vis[tx][ty] = vis[cur.x][cur.y] - 1;
        }
    }
    for(auto [x,y] : trigger) {
        done[x][y] = 1;
        vis[x][y] = max(vis[x][y], grid[x][y]);
        explode(x,y);
    }
    return;
}
bool check(int radius) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            done[i][j] = 0;
            vis[i][j] = -1;
        }
    }
    vis[st.x][st.y] = radius;
    done[st.x][st.y] = 1;
    explode(st.x,st.y);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cnt += (vis[i][j] >= 0);
        }
    }
    return cnt >= q;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> N >> M >> q;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
        cin >> grid[i][j];
        if(grid[i][j] == -2) st = {i,j};
    }
    int l = 0, r = 500*500+1;
    while(l+1 != r) {
        int m = (l+r) >> 1;
        if(check(m)) r = m;
        else l = m;
    }
    return cout<<r<<'\n',0;
}