// Author : Zhenzhe
// Problem : https://oj.ntucpc.org/problems/959
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int H,W,arrange[15][15];
struct Special {int x,y,area;};
vector<Special> place;
bool valid(int x, int y, int h, int w) {
    if(x + h - 1 > H || y + w - 1 > W) return false;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(arrange[x+i][y+j] > 0) return false; 
        }
    } 
    return true;
}
void apply(int x, int y, int h, int w, int id) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            arrange[x+i][y+j] = id;
        }
    }
}
bool dfs(int idx) {
    if(idx == (int)place.size()) return true;
    auto &[x,y,area] = place[idx];
    for(int h=1; h<=area; h++) {
        if(area % h != 0) continue;
        int w = area / h;
        for(int sx = max((int) 1,x-h+1); sx <= x; sx++) {
            for(int sy = max((int) 1,y-w+1); sy <= y; sy++) {
                if(!valid(sx, sy, h, w)) continue;
                apply(sx, sy, h, w, idx+1);
                if(dfs(idx+1)) return true;
                apply(sx, sy, h, w, 0);
            }
        }
    }
    return false;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> H >> W;
    int x;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> x;
            if(x > 0) place.push_back({i,j,x});
        }
    }
    dfs(0);
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cout << arrange[i][j] << " \n"[j==W];
        }
    }
    return 0;
}