// Problem : https://atcoder.jp/contests/abc400/tasks/abc400_d
// Tags : 0-1 BFS
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;

static constexpr int MAXN = 1005, INF = 1e18;
const pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int R, C, sx, sy, tx, ty;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            dist[i][j] = INF;
        }
    }
    cin >> sx >> sy >> tx >> ty;
    sx--; sy--; tx--; ty--;

    auto inRange = [&](int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    };

    deque<pair<int,int>> dq;
    dq.push_back({sx, sy});
    dist[sx][sy] = 0;

    while (!dq.empty()) {
        auto [cx, cy] = dq.front();
        dq.pop_front();
        if (cx == tx && cy == ty) break;

        for (auto [dx, dy] : dir) {
            int nx = cx + dx, ny = cy + dy;
            if (inRange(nx, ny) && grid[nx][ny] == '.') {
                if (dist[cx][cy] < dist[nx][ny]) {
                    dist[nx][ny] = dist[cx][cy];
                    dq.push_front({nx, ny});
                }
            }

            for (int step = 1; step <= 2; step++) {
                int kx = cx + dx * step;
                int ky = cy + dy * step;

                if (inRange(kx, ky)) {
                    if (dist[cx][cy] + 1 < dist[kx][ky]) {
                        dist[kx][ky] = dist[cx][cy] + 1;
                        dq.push_back({kx, ky});
                    }
                }
            }
        }
    }

    cout << dist[tx][ty] << "\n";
    return 0;
}