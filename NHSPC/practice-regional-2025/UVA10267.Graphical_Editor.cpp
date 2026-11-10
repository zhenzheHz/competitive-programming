// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=f435
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    char operation,grid[255][255],color;
    int N,M,x,y,x1,x2,y1,y2;
    string line;
    while(getline(cin, line)) {
        stringstream ss;
        ss << line;
        ss >> operation;
        if(operation == 'X') break;
        if(operation == 'I') {
            ss >> N >> M;
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    grid[j][i] = 'O';
                }
            }
        }
        else if(operation == 'C') {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    grid[i][j] = 'O';
                }
            }
        }
        else if(operation == 'L') {
            ss >> x >> y >> color;
            x--, y--;
            grid[y][x] = color;
        }
        else if(operation == 'V') {
            ss >> x >> y1 >> y2 >> color;
            x--, y1--, y2--;
            if(y1 > y2) swap(y1,y2);
            for(int i = y1; i <= y2; i++) {
                grid[i][x] = color;
            } 
        }
        else if(operation == 'H') {
            ss >> x1 >> x2 >> y >> color;
            x1--, x2--, y--;
            if(x1 > x2) swap(x1,x2);
            for(int i = x1; i <= x2; i++) {
                grid[y][i] = color;
            } 
        }
        else if(operation == 'K') {
            ss >> x1 >> y1 >> x2 >> y2 >> color;
            x1--, y1--, x2--, y2--;
            if(x1 > x2) swap(x1,x2);
            if(y1 > y2) swap(y1,y2);
            for(int i = x1; i <= x2; i++) {
                for(int j = y1; j <= y2; j++) {
                    grid[j][i] = color;
                }
            }
        }
        else if(operation == 'F') {
            ss >> x >> y >> color;
            x--, y--;
            // you will get std::bad_alloc without this line
            if(grid[y][x] == color) continue;
            #define inside(i,j) (i >=0 && i < N && j >= 0 && j < M)
            queue<pair<int,int>> q;
            char mark = grid[y][x];
            grid[y][x] = color;
            q.push({y,x});
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(auto dx : {1,0,-1}) {
                    for(auto dy : {1,0,-1}) {
                        if(dx != 0 && dy != 0) continue;
                        if(dx == 0 && dy == 0) continue;
                        int tx = cur.first + dx, ty = cur.second + dy;
                        if(inside(tx,ty) && grid[tx][ty] == mark) {
                            q.push({tx,ty});
                            grid[tx][ty] = color;
                        }
                    }
                }
            }
        }
        else if(operation == 'S') {
            string filename;
            ss >> filename;
            cout << filename << '\n';
            for(int i = 0; i < M; i++) {
                for(int j = 0; j < N; j++) {
                    cout << grid[i][j];
                }
                cout << '\n';
            }
        }
        else {
            string tmp;
            while(ss >> tmp) {
                continue;
            }
        }
    }
    return 0;
}