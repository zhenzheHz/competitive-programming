// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2019 北市賽 pC
// Tags : 一筆畫問題(圖論)
// Problem : https://tioj.ck.tp.edu.tw/problems/2171
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5;
int A,B,S,M,K,vis[MAXN];
vector<int> g[MAXN];
int odd_node = 0;
void dfs(int cur) {
    vis[cur] = 1;
    odd_node += (g[cur].size() & 1);
    for(auto nxt : g[cur]) {
        if(!vis[nxt]) dfs(nxt);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    memset(vis,0,sizeof(vis));
    cin >> A >> B >> S >> M >> K;
    for(int i=0;i<K;i++) {
        int a,b,m;
        cin >> a >> b >> m;
        g[a].push_back(b+A);
        g[b+A].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<=A+B;i++) {
        if(vis[i] || g[i].empty()) continue;
        odd_node = 0;
        dfs(i);
        ans += max((int) 1,odd_node/2);
    }
    cout << ans << '\n';
}