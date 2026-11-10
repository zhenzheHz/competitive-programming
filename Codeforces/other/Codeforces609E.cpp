// Problem : https://codeforces.com/contest/609/problem/E
// Tag : spanning tree
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, LOGN = 30;
struct Edge {
    int src,des,w,id;
    bool operator<(const Edge &cmp) const {
        return w < cmp.w;
    }
};
struct Dsu {
    size_t sz;
    int pa[MAXN];
    void init(int _sz) {
        sz = _sz;
        for(int i=0;i<MAXN;i++) pa[i] = i;
    }  
    int find(int x) {return pa[x] == x? x : pa[x] = find(pa[x]);}
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        return pa[a]=b,true;
    }
};
vector<int> used(MAXN);
vector<Edge> lst, g[MAXN];

int par[MAXN][LOGN], dp[MAXN][LOGN], depth[MAXN];
void dfs(int cur, int from) {
    depth[cur] = depth[from] + 1;
    par[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        par[cur][i] = par[par[cur][i-1]][i-1];
        dp[cur][i] = max(dp[cur][i-1],dp[par[cur][i-1]][i-1]);
    }
    for(auto nxt : g[cur]) {
        if(nxt.des == from) continue;
        par[nxt.des][0] = cur;
        dp[nxt.des][0] = (int64_t) nxt.w;
        dfs(nxt.des,cur);
    }
}

int maxLCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int tmp = 0, power = 0;
    while(diff) {
        if(diff & 1) {
            tmp = max(tmp, dp[a][power]);
            a = par[a][power];
        }
        diff >>= 1, power++;
    }
    if(a == b) return tmp;
    for(int j=LOGN-1;j>=0;j--) {
        if(par[a][j] == par[b][j]) continue;
        tmp = max(tmp, dp[a][j]);
        tmp = max(tmp, dp[b][j]);
        a = par[a][j], b = par[b][j];
    }
    return max({tmp, dp[a][0], dp[b][0]});
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        lst.push_back({a,b,x,i});
    }
    sort(lst.begin(),lst.end());
    Dsu kruskal;
    kruskal.init(n+1);
    int mst = 0;
    for(int i=0;i<m;i++) {
        auto ed = lst[i];
        if(kruskal.merge(ed.src,ed.des)) {
            mst += ed.w;
            used[ed.id] = 1;
            g[ed.src].push_back({ed.src,ed.des,ed.w,ed.id});
            g[ed.des].push_back({ed.des,ed.src,ed.w,ed.id});
        }
    }
    dfs(1,1);
    sort(lst.begin(),lst.end(), [&](const Edge &A, const Edge &B) {
        return A.id < B.id;
    });
    for(int i=0;i<m;i++) {
        if(used[i]) cout << mst << '\n';
        else cout << mst + lst[i].w - maxLCA(lst[i].src,lst[i].des) << '\n';
    }
    return 0;
}