#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int dx[] = {-1,-1,1,1}, dy[] = {-1,1,-1,1};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int R,C;
    cin >> R >> C;
    char g[R][C];
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i+1 < C; i++) {
        bool check = 1;
        int x = 1, y = i;
        if(g[x][y] == '#') check = 0;
        for(int k = 0; k < 4; k++) {
            int tx = x + dx[k], ty = y + dy[k];
            if(g[tx][ty] == '#') check = 0;
        }
        ans += check;
        if(check) {
            for(int k = 0; k < 4; k++) {
                int tx = x + dx[k], ty = y + dy[k];
                g[tx][ty] = '#';
            }
        }
    }
    cout << ans;
}