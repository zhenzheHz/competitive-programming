// Author : Zhenzhe
// Time : 2024 / 12 / 05
// Info : 2017 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2037
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
void solve() {
    int p,q,k;
    cin >> p >> q >> k;
    vector<int> g[MAXN];
    int match[MAXN];
    bitset<MAXN> vis;
    memset(match, -1, sizeof(match));
    for(int i=0;i<k;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    function<bool(int)> dfs = [&](int cur) {
        if(vis[cur]) return false;
        vis[cur] = 1;
        for(int nxt : g[cur]) {
            if(match[nxt] == -1 || dfs(match[nxt]))
                return match[nxt]=cur,true;
        } 
        return false;
    };
    int ans = 0;
    for(int i=1;i<=p;i++) {
        vis.reset();
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 0;
    cin >> test;
    while(test--) solve();
}