// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=a634
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T> 
void debug(T&&... args) {
    ((cerr << args << ' '), ...); cerr << '\n';
}
int board[9][9], dis[9][9];
int sx,sy,ex,ey;
const pair<int,int> dxy[] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
bool inside(int x,int y) {
    return (x > 0 && y > 0 && x < 9 && y < 9);
}
void conv(string &x,int &dx,int &dy) {
    int r = x[0] - 'a' + 1;
    int c = x[1] - '0';
    dx = r, dy = c;
    return;
}
int bfs(int X,int Y) {
    queue<pair<int,int>> q;
    q.push({X,Y});
    dis[X][Y] = 0;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy] : dxy) {
            int tx = x + dx, ty = y + dy;
            if(!inside(tx,ty) || board[tx][ty] == -1) continue;
            if(dis[tx][ty] >= 0) continue;
            q.push({tx,ty});
            dis[tx][ty] = dis[x][y] + 1;
        }
    }
    return dis[ex][ey];
}
vector<string> path;
string tmp = "";
int shortest;
void dfs(int x,int y) {
    tmp.push_back('a' + x - 1);
    tmp.push_back('0' + y);
    if(x == ex && y == ey) {
        if(tmp.empty()) return;
        path.push_back(tmp);
    }else {
        for(auto [dx,dy] : dxy) {
            int tx = x + dx, ty = y + dy;
            if(!inside(tx,ty) || board[tx][ty] == -1) continue;
            if(dis[tx][ty] != dis[x][y] + 1 || dis[tx][ty] > shortest) continue;
            dfs(tx,ty);
        }
    }
    tmp.pop_back();
    tmp.pop_back();
}
void solve(string st, string ed) {
    memset(board, 0, sizeof(board));
    memset(dis, -1, sizeof(dis));
    path.clear();
    tmp = "";
    conv(st,sx,sy);
    conv(ed,ex,ey);
    string ob;
    while(cin >> ob) {
        if(ob == "xx") break;
        int xx,yy;
        conv(ob, xx, yy);
        board[xx][yy] = -1;
    }
    shortest = bfs(sx,sy);
    dfs(sx,sy);
    cout << "The shortest solution is " << shortest << " move(s).\n";
    sort(path.begin(), path.end());
    for(auto &trail : path) {
        cout << "Solution: ";
        for(int i = 0; i < (int) trail.size(); i += 2) {
            cout << trail[i] << trail[i+1] << ' ';
        }
        cout << '\n';
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    while(cin >> a >> b) {
        solve(a,b);
    }
    return 0;
}