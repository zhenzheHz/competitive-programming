// Author : Zhenzhe
// Time : 2024 / 10 / 17
// Problem : https://zerojudge.tw/ShowProblem?problemid=c129
#include <bits/stdc++.h>
using namespace std;
void solve(int row, int col);
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int row, col;
    while(cin >> row >> col && row && col) {
        solve(row, col);
    }
}
const int dx[] = {-1,1,0,0,-1,-1,1,1}, dy[] = {0,0,-1,1,-1,1,-1,1};
void solve(int row, int col) {
    vector<vector<bool>> vis(row, vector<bool> (col,false));
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            char c; cin >> c;
            vis[i][j] = (c == '*');
        }
    }

    #define inRange(i,j) (i>=0&&i<row&&j>=0&&j<col)
    function<void(int,int)> dfs = [&](int x, int y) {
        if(vis[x][y]) return;
        vis[x][y] = true;
        for(int next = 0; next < 8; next++) {
            if(inRange(x+dx[next], y+dy[next]))
                dfs(x+dx[next], y+dy[next]);
        }
    };  

    int ans = 0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(!vis[i][j]) {
                dfs(i, j);
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}