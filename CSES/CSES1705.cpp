// Problem : https://cses.fi/problemset/task/1705
// Tags : Block-Cut-Tree, LCA
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int MAXN = 3e5 + 5;
vector<int> g[MAXN], dfn(MAXN), low(MAXN), isAP(MAXN), id(MAXN);
vector<int> stk;
vector<vector<int>> bcc, bct;
int timer = 0;

void dfs(int cur, int from) {
    dfn[cur] = low[cur] = ++timer;
    stk.push_back(cur);
    for (auto nxt : g[cur]) {
        if (nxt == from) continue;
        if (dfn[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
        } else {
            dfs(nxt, cur);
            low[cur] = min(low[cur], low[nxt]);
            if (low[nxt] >= dfn[cur]) {
                isAP[cur] = (dfn[cur] > 1 || dfn[nxt] > 2);
                bcc.push_back({cur});
                while (bcc.back().back() != nxt) {
                    bcc.back().push_back(stk.back());
                    stk.pop_back();
                }
            }
        }
    }
}

vector<int> in(MAXN), out(MAXN);
vector<vector<int>> pa(MAXN, vector<int>(30));
int logN;

void dfs2(int node,int from){
    static int times = 0;
    int p = from;
    for(int i=0;i<=logN;i++){
        pa[node][i] = p;
        p = pa[p][i];
    }
    in[node] = times++;
    for(int nxt : bct[node]){
        if(nxt == from)continue;
        dfs2(nxt,node);
    }
    out[node] = times++;
}

bool isAnc(int par, int son) {
    return in[par] <= in[son] && out[par] >= out[son];
}

int LCA(int a,int b){
    if(isAnc(a,b))return a;
    if(isAnc(b,a))return b;
    for(int j=logN;j>=0;j--){
        if(isAnc(pa[a][j],b))continue;
        a = pa[a][j];
    }
    return pa[a][0];
}

bool check(int x,int y,int z) {
    int lca = LCA(x, y);
    int lca1 = LCA(x, z);
    int lca2 = LCA(y, z);

    if (lca == z || (lca1 == lca && lca2 == z) || (lca2 == lca && lca1 == z)) {
        return true;
    }
    return false;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(1, 1);

    // Build Block-Cut-Tree
    int bcc_id = 0;
    for (int i = 1; i <= n; i++) {
        if (isAP[i]) {
            id[i] = bcc_id++;
            bct.push_back({});
        }
    }
    for (auto &comp : bcc) {
        int node = bcc_id++;
        bct.push_back({});
        for (auto v : comp) {
            if (isAP[v]) {
                bct[id[v]].push_back(node);
                bct[node].push_back(id[v]);
            } else {
                id[v] = node;
            }
        }
    }

    timer = 0;
    logN = log2(n + 1);
    dfs2(0, 0);

    // Queries
    while (q--) {
        int a, b, c, tmp;
        cin >> a >> b >> c;
        if(a == c || b == c || (isAP[c] && check(id[a],id[b],id[c])))
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
    return 0;
}