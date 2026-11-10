// Problem : https://atcoder.jp/contests/abc075/tasks/abc075_c
// Tags : Bridges-Connected-Component
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 55;
vector<int> g[MAXN], dfn(MAXN, 0), low(MAXN, 0);
int timer = 1, bridges = 0;
void dfs(int cur, int from) {
    dfn[cur] = low[cur] = timer++;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        if(!dfn[nxt]) {
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
        }else low[cur] = min(low[cur], dfn[nxt]);
    }
    if(low[cur] == dfn[cur] && cur != from) bridges++;  
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    while(m--) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    return cout<<bridges,0;
}