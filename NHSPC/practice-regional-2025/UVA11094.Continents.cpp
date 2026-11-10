// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=e584
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
char world[25][25];
bool valid[25][25], vis[25][25];
const pair<int,int> dxy[] = {{1,0},{-1,0},{0,1},{0,-1}};
int N,M,tmp_cnt = 0;
void dfs(int x,int y) {
    if(x < 0 || x >= N || vis[x][y] || !valid[x][y]) return;
    vis[x][y] = 1;
    tmp_cnt += 1;
    for(auto [dx,dy] : dxy) {
        dfs(x+dx,(y+dy+M)%M);
    }
}
void solve() {
    int sx,sy;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> world[i][j];
            vis[i][j] = 0;
        }
    }
    cin >> sx >> sy;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            valid[i][j] = (world[i][j] == world[sx][sy]);
        }
    }
    dfs(sx,sy);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(valid[i][j] && !vis[i][j]) {
                tmp_cnt = 0;
                dfs(i,j);
                ans = max(ans, tmp_cnt);
            }
        }
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    while(cin >> N >> M) {
        solve();
    }
    return 0;
}