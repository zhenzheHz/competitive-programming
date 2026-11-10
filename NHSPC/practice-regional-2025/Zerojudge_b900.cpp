// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=b900
// Tag : 2016 高雄市 資訊學科能力 複賽 3
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int W,H;
    cin >> W >> H;
    char grid[H+1][W<<1];
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < 2*W-1; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < 2*W-1; i+=2) {
        int cur = i;
        for(int j = 0; j < H; j++) {
            if(cur-2 >= 0 && grid[j][cur-1] == '-') cur = cur-2;
            else if(cur+2 < 2*W-1 && grid[j][cur+1] == '-') cur = cur+2;
        }
        cout << cur / 2 + 1 << ' ';
    }
    return 0;
}