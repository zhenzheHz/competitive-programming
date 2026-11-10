// Problem : https://codeforces.com/problemset/problem/118/E
// Tags : Bridges-Coneected-Component
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, MAXM = 3e5+5;
vector<int> g[MAXN], dfn(MAXN,0), low(MAXN,0);
vector<pair<int,int>> edges;
bool haveBridge = false;
int timer = 1;
void dfs(int cur, int from) {
    dfn[cur] = low[cur] = timer++;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        if(!dfn[nxt]) {
            edges.emplace_back(cur, nxt);
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
        } else {
            if(dfn[nxt] < dfn[cur]) edges.emplace_back(cur, nxt);
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    if(low[cur] == dfn[cur] && cur != from) haveBridge = true;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    if(haveBridge) return cout<<0,0;
    for(auto [src, des] : edges) {
        cout << src << ' ' << des << '\n';
    }
}