// Problem : https://codeforces.com/problemset/problem/1000/E
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3e5+5;

vector<int> g[MAXN], low(MAXN), dfn(MAXN), bcc(MAXN);
int timer = 1, x = 1;
vector<int> cc;
vector<pair<int,int>> bridges;
void dfs(int cur,int from) {
    dfn[cur] =  low[cur] = timer++;
    cc.push_back(cur);
    for(int &nxt : g[cur]) {
        if(nxt == from) continue;
        if(!dfn[nxt]) {
            dfs(nxt,cur);
            low[cur] = min(low[cur], low[nxt]);
        }else low[cur] = min(low[cur], dfn[nxt]);
    }
    if(low[cur] == dfn[cur]) {
        if(cur != from) bridges.push_back({cur,from});
        int now;
        do {
            now = cc.back();
            bcc[now] = x;
            cc.pop_back();
        }while(now != cur);
        x++;
    }
}

vector<int> btree[MAXN];
int max_depth = 0, node = -1;
void dfs2(int cur, int from, int depth) {
    if(depth > max_depth) {
        max_depth = depth;
        node = cur;
    }
    for(int &nxt : btree[cur]) {
        if(nxt == from) continue;
        dfs2(nxt,cur,depth+1);
    }
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
    // for(int i=1;i<=n;i++) cout << bcc[i] << " \n"[i==n]; 
    for(auto bridge : bridges) {
        // cout << bridge.first << ' ' << bridge.second << '\n';
        int a = bcc[bridge.first], b = bcc[bridge.second];
        btree[a].push_back(b);
        btree[b].push_back(a);
    }
    dfs2(1,1,0);
    max_depth = 0;
    dfs2(node,node,0);
    return cout<<max_depth,0;
}