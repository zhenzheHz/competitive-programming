// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=b343
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5;
void solve() {
    int n,m,l,ans = 0;
    cin >> n >> m >> l;
    vector<int> graph[MAXN],vis(MAXN,0);
    while(m--) {
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    function<void(int)> dfs = [&](int cur) {
        if(vis[cur]) return;
        ans += 1;
        vis[cur] = 1;
        for(auto nxt : graph[cur]) {
            dfs(nxt);
        }
    };
    while(l--) {
        int x;
        cin >> x;
        dfs(x);
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}