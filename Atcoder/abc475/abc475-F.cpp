#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R+1, vector<int>(C+1, 0));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = (ch == '.');
        }
    }
    if (R > C) {
        vector<vector<int>> trans(C+1, vector<int>(R+1, 0));
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                trans[j][i] = grid[i][j];
            }
        }
        swap(R, C);
        grid = trans;
    }
    vector<vector<int>> nxt(R+1, vector<int>(C+2, C+1));
    for (int i = 1; i <= R; i++) {
        for (int j = C; j >= 1; j--) {
            if (grid[i][j] == 1) {
                nxt[i][j] = j;
            } else {
                nxt[i][j] = nxt[i][j + 1];
            }
        }
    }
    int ans = 0;
    for (int r1 = 1; r1 <= R; r1++) {
        vector<int> white(C + 1, 0);
        for (int r2 = r1; r2 <= R; r2++) {
            for (int j = 1; j <= C; j++) {
                if (grid[r2][j] == 1) white[j] = 1;
            }
            vector<int> S(C + 2, 0);
            for (int j = C; j >= 1; j--) {
                S[j] = S[j + 1] + white[j];
            }
            for (int c1 = 1; c1 <= C; c1++) {
                if (!white[c1]) continue;
                int limit = max(nxt[r1][c1], nxt[r2][c1]);
                if (limit <= C) ans += S[limit];
            }
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}