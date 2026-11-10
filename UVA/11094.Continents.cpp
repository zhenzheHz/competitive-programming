// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=e584
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve(int n,int m) {
    int a,b;
    vector<vector<char>> world(n,vector<char> (m));
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin >> world[i][j];
    }
    cin >> a >> b;
    char mark = world[a][b];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(world[i][j] != mark) visited[i][j] = 1;
    int count = 0;
    function<void(int,int)> dfs = [&](int x,int y) {
        if(visited[x][y]) return;
        visited[x][y] = 1;
        count += 1;
        dfs(x,(y+1+m)%m);
        dfs(x,(y-1+m)%m);
        if(x-1 >= 0) dfs(x-1,y);
        if(x+1 < n) dfs(x+1,y);
    };
    dfs(a,b);
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(visited[i][j]) continue;
            count = 0;
            dfs(i,j);
            ans = max(ans,count);
        }
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m) {
        solve(n,m);
    }
}