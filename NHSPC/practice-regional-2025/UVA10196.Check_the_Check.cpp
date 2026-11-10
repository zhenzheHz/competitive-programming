// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=d368
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
vector<string> grid(8);
bool inside(int x,int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
bool check_line(int x,int y) {
    for(auto dx : {1,0,-1}) {
        for(auto dy : {1,0,-1}) {
            if(abs(dx) + abs(dy) != 1) continue;
            int nx = x + dx, ny = y + dy;
            while(inside(nx,ny)) {
                if(grid[nx][ny] != '.' ) {
                    if(isupper(grid[x][y]) && (grid[nx][ny] == 'r' || grid[nx][ny] == 'q')) return 1;
                    if(islower(grid[x][y]) && (grid[nx][ny] == 'R' || grid[nx][ny] == 'Q')) return 1;
                    break; // be blocked
                }
                nx += dx, ny += dy;
            }
        }
    }
    return 0;
}
bool check_diagonal(int x,int y) {
    for(auto dx : {1,-1}) {
        for(auto dy : {1,-1}) {
            int nx = x + dx, ny = y + dy;
            while(inside(nx,ny)) {
                if(grid[nx][ny] != '.' ) {
                    if(isupper(grid[x][y]) && (grid[nx][ny] == 'b' || grid[nx][ny] == 'q')) return 1;
                    if(islower(grid[x][y]) && (grid[nx][ny] == 'B' || grid[nx][ny] == 'Q')) return 1;
                    break; // be blocked
                }
                nx += dx, ny += dy;
            }
        }
    }
    return 0;
}
bool check_knight(int x,int y) {
    for(auto dx : {1,2,-1,-2}) {
        for(auto dy : {1,2,-1,-2}) {
            if(abs(dx) == abs(dy)) continue;
            int tx = x + dx, ty = y + dy;
            if(!inside(tx,ty)) continue;
            if(isupper(grid[x][y]) && grid[tx][ty] == 'n') return 1;
            if(islower(grid[x][y]) && grid[tx][ty] == 'N') return 1;  
        }
    }
    return 0;
}
bool check_pawn(int x,int y) {
    if(isupper(grid[x][y])) {
        if(inside(x-1,y-1) && grid[x-1][y-1] == 'p') return 1;
        if(inside(x-1,y+1) && grid[x-1][y+1] == 'p') return 1; 
    }
    else {
        if(inside(x+1,y-1) && grid[x+1][y-1] == 'P') return 1;
        if(inside(x+1,y+1) && grid[x+1][y+1] == 'P') return 1;
    }
    return 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int GAME = 1;
    while(true) {
        for(int i = 0; i < 8; i++) {
            cin >> grid[i];
        }
        bool stop = true;
        pair<int,int> white(-1,-1), black(-1,-1);
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(grid[i][j] != '.') stop = 0;
                if(grid[i][j] == 'K') white = {i,j};
                if(grid[i][j] == 'k') black = {i,j};
            }
        }
        if(stop) break;
        // check white
        bool check_white = check_pawn(white.x,white.y);
        check_white |= check_knight(white.x,white.y);
        check_white |= check_diagonal(white.x,white.y);
        check_white |= check_line(white.x,white.y);
        // check black
        bool check_black = check_pawn(black.x,black.y);
        check_black |= check_diagonal(black.x,black.y);
        check_black |= check_knight(black.x,black.y);
        check_black |= check_line(black.x,black.y);
        // Print
        // Game #1: black king is in check.
        cout << "Game #" << GAME++ << ": ";
        if(check_white) cout << "white";
        else if(check_black) cout << "black";
        else cout << "no";
        cout << " king is in check.\n";
    }
    return 0;
}