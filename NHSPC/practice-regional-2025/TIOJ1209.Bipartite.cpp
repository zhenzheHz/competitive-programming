// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/1209
#include <bits/stdc++.h>
#define int int64_t
#define UNCOLORED 0
#define RED 1
#define BLUE 2
using namespace std;
static constexpr int MAXN = 4e4+5;
vector<int> g[MAXN], color(MAXN);
int n,m;
bool dfs(int cur, int paint) {
    color[cur] = paint;
    for(auto nxt : g[cur]) {
        if(color[nxt] == UNCOLORED) {
            if(!dfs(nxt, 3-color[cur])) {
                return 0;
            }
        }
        else if(color[cur] == color[nxt]) {
            return 0;
        }
    }
    return 1;
}
void solve() {
    for(int i = 1; i < MAXN; i++) g[i].clear();
    for(int i = 1; i < MAXN; i++) color[i] = UNCOLORED;
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool valid = 1;
    for(int i = 1; i <= n; i++) {
        if(color[i] == UNCOLORED && !dfs(i,RED)) {
            valid = 0;
        }
    }
    cout << (valid? "Yes\n" : "No\n");
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        solve();
    }
    return 0;
}