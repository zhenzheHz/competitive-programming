// Author : Zhenzhe
// Time : 2024 / 11 / 02
// Problem : https://zerojudge.tw/ShowProblem?problemid=d365
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int WORLD = 1;
void solve() {
    int r,c;
    cin >> r >> c;
    vector<vector<char>> grid(r,vector<char> (c));
    vector<vector<bool>> vis(r,vector<bool> (c,false));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> grid[i][j];
        }
    }
    function<void(int,int)> dfs=[&](int x,int y) {
        vis[x][y] = 1;
        if(x-1>=0 && grid[x][y] == grid[x-1][y] && !vis[x-1][y])
            dfs(x-1,y);
        if(x+1<r && grid[x][y] == grid[x+1][y] && !vis[x+1][y])
            dfs(x+1,y);
        if(y-1>=0 && grid[x][y] == grid[x][y-1] && !vis[x][y-1])
            dfs(x,y-1);
        if(y+1<c && grid[x][y] == grid[x][y+1] && !vis[x][y+1])
            dfs(x,y+1); 
    };
    map<char,int> area;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!vis[i][j]) {
                dfs(i,j);
                area[grid[i][j]] += 1;
            }
        }
    }
    set<pair<int,char>> Sorted;
    for(auto [sym, times] : area) {
        Sorted.insert({-times,sym});
    }
    cout << "World #" << WORLD++ << '\n';
    for(auto it=Sorted.begin();it!=Sorted.end();it = next(it)) {
        cout << it->second << ": " << -1*it->first << '\n';
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}