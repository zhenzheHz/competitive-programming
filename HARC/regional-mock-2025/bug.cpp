#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct State {
    int x, y, dir;
};
void print(int x,int y) {
    cout << x << ' ' << y << '\n';
}
void solve(int n) {
    int sx, sy, d;
    cin >> sx >> sy >> d;
    vector<vector<int>> x(101), y(101);
    for(int i = 0; i < n; i++) {
        int bx, by;
        cin >> bx >> by;
        x[bx].push_back(by);
        y[by].push_back(bx);
    }
    for(int i = 0; i < 101; i++) {
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
    }
    int cdx = 0;
    int vis[101][101][4];
    memset(vis, -1, sizeof(vis));
    while(d > 0) {
        if(vis[sx][sy][cdx] != -1) {
            int loop_len = vis[sx][sy][cdx] - d;
            d %= loop_len;
        }
        vis[sx][sy][cdx] = d;
        int nx = sx, ny = sy;
        if(cdx == 0) {
            auto f = upper_bound(y[sy].begin(), y[sy].end(), sx);
            nx = (f == y[sy].end() ? sx + d : *f - 1);
            int step = nx - sx;
            if(step >= d) { sx += d; break; }
            sx = nx; d -= step;
        } else if(cdx == 1) {
            auto f = upper_bound(x[sx].begin(), x[sx].end(), sy);
            ny = (f == x[sx].end() ? sy + d : *f - 1);
            int step = ny - sy;
            if(step >= d) { sy += d; break; }
            sy = ny; d -= step;
        } else if(cdx == 2) {
            auto f = upper_bound(y[sy].begin(), y[sy].end(), sx);
            if(f == y[sy].begin()) { sx -= d; break; }
            f = prev(f);
            nx = *f + 1;
            int step = sx - nx;
            if(step >= d) { sx -= d; break; }
            sx = nx; d -= step;
        } else {
            auto f = upper_bound(x[sx].begin(), x[sx].end(), sy);
            if(f == x[sx].begin()) { sy -= d; break; }
            f = prev(f);
            ny = *f + 1;
            int step = sy - ny;
            if(step >= d) { sy -= d; break; }
            sy = ny; d -= step;
        }
        cdx = (cdx + 1) % 4;
    }
    print(sx, sy);
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        solve(n);
    }
}
