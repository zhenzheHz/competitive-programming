#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e5+5,LOGN= 21;
int n,m;
struct Edge {int u,v,w,id;};
struct DSU {
    int pa[MAXN];
    void init() {
        for(int i=0;i<MAXN;i++) pa[i] = i;
    }
    int find(int x) {
        if(x == pa[x]) return x;
        return pa[x] = find(pa[x]);
    }
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        pa[a] = b;
        return true;
    }
};
vector<Edge> g[MAXN],lst;

int32_t dp[MAXN][LOGN],depth[MAXN];
int64_t mx[MAXN][LOGN];

void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
        mx[cur][i] = max(mx[cur][i-1],mx[dp[cur][i-1]][i-1]);
    }
    for(auto nxt : g[cur]) {
        if(nxt.v == from) continue;
        dp[nxt.v][0] = cur;
        mx[nxt.v][0] = (int64_t) nxt.w;
        dfs(nxt.v,cur); 
    }
}

int64_t max_LCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b], power = 0;
    int64_t tmp = 0;
    while(diff) {
        if(diff & 1) {
            tmp = max(tmp, mx[a][power]);
            a = dp[a][power];
        }
        power += 1;
        diff >>= 1;
    }
    if(a == b) return tmp;
    for(int j=LOGN-1;j>=0;j--) {
        if(dp[a][j] == dp[b][j]) continue;
        tmp = max({tmp,mx[a][j],mx[b][j]});
        a = dp[a][j], b = dp[b][j];
    }
    return max({tmp,mx[a][0],mx[b][0]});
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        lst.push_back({a,b,x,i});
    }
    sort(lst.begin(),lst.end(),[&](const Edge a,const Edge b) {
        return a.w < b.w;
    });
    DSU kruskal;
    kruskal.init();
    int64_t mst = 0;
    vector<bool> inMSTree(m,0);
    for(int i=0;i<m;i++) {
        if(kruskal.merge(lst[i].u,lst[i].v)) {
            g[lst[i].u].push_back(lst[i]);
            g[lst[i].v].push_back({lst[i].v,lst[i].u,lst[i].w,lst[i].id});
            mst += lst[i].w;
            inMSTree[lst[i].id] = 1;
        }
    }
    dfs(1,1);
    sort(lst.begin(),lst.end(),[&](Edge a,Edge b){
        return a.id < b.id;
    });
    for(int i=0;i<m;i++) {
        if(inMSTree[i]) cout << mst << '\n';
        else {
            int64_t ans = (int64_t) mst - max_LCA(lst[i].u,lst[i].v) + (int64_t)lst[i].w;
            cout << ans << '\n';
        }
    }
    return 0;
}