// Problem : https://www.luogu.com.cn/problem/P1967
// Tag : 最大生成樹 + LCA
#include <bits/stdc++.h>
#define int int64_t
static constexpr int MAXN = 1e4+5, MAXM = 5e4+5, LOGN = 21;
using namespace std;
struct Edge {
    int u,v,w,id;
    bool operator<(const Edge &cmp) const {
        return w < cmp.w;
    }
};
struct Dsu {
    int pa[MAXN];
    void init() {for(int i=0;i<MAXN;i++) pa[i]=i;}
    int find(int x) {return (x == pa[x]? x : pa[x] = find(pa[x]));};
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        return pa[a]=b,true;
    }
};
vector<Edge> g[MAXN];
bool inTree[MAXM];
int depth[MAXN], dp[MAXN][LOGN], mn[MAXN][LOGN];
void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
        mn[cur][i] = min(mn[cur][i-1],mn[dp[cur][i-1]][i-1]);
    }
    for(auto nxt : g[cur]) {
        if(nxt.v == from) continue;
        dp[nxt.v][0] = cur;
        mn[nxt.v][0] = nxt.w;
        dfs(nxt.v,cur);
    }
}

int minLCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int power = 0, tmp_min = 1e18;
    while(diff) {
        if(diff & 1) tmp_min = min(tmp_min,mn[a][power]), a = dp[a][power];
        power += 1, diff >>= 1;
    }
    if(a == b) return tmp_min;
    for(int i=LOGN-1;i>=0;i--) {
        if(dp[a][i] == dp[b][i]) continue;
        tmp_min = min({tmp_min,mn[a][i],mn[b][i]});
        a = dp[a][i], b = dp[b][i];
    } 
    return min({tmp_min,mn[a][0],mn[b][0]});
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<Edge> lst(m);
    for(int i=0;i<m;i++) {
        cin >> lst[i].u >> lst[i].v >> lst[i].w;
        lst[i].id = i;
    }
    sort(lst.rbegin(),lst.rend());
    Dsu kr;
    kr.init();
    int mst = 0;
    for(auto [u,v,w,id] : lst) {
        if(kr.merge(u,v)) {
            mst += w;
            inTree[id] = 1;
            g[u].push_back({u,v,w,id});
            g[v].push_back({v,u,w,id});
        }
    }

    for(int i=1;i<=n;i++) {
        if(!depth[i]) dfs(i,i);
    }

    int q;
    cin >> q;
    while(q--) {
        int src,des;
        cin >> src >> des;
        int ans = minLCA(src,des);
        if(ans == 0) ans = -1;
        cout << ans << '\n';
    }
}