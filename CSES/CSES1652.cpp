// Problem : https://cses.fi/problemset/task/1652
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
int forest[MAXN][MAXN], prefix[MAXN][MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        char c;cin >> c;
        forest[i][j] = (c == '*');
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            prefix[i][j] = forest[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    // for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << prefix[i][j] << " \n"[j==n];
    while(q--) {
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        int ans = prefix[rx][ry] - prefix[lx-1][ry] - prefix[rx][ly-1] + prefix[lx-1][ly-1];
        cout << ans << '\n';
    }
}