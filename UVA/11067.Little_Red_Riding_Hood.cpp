// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=e581
// Author : Zhenzhe
// Time : 2024 / 11 / 03
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 105;

void solve(int w, int h) {
    int n;
    cin >> n;
    vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0)), danger(w + 1, vector<int>(h + 1, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        danger[x][y] = 1;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (danger[i][j]) {
                dp[i][j] = 0;
            } else {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
    }
    int ans = dp[w][h];
    if (ans <= 0)
        cout << "There is no path.\n";
    else if (ans == 1)
        cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
    else
        cout << "There are " << ans << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int w, h;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;
        solve(w, h);
    }
}