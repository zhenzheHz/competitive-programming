#include <bits/stdc++.h>
using namespace std;
static constexpr int MAXN = 5e5+5, LOGN = 20;
struct edge {int src,des,w,id;};
struct dsu {
    int sz,pa[MAXN];
    void init(int s) {
        sz = s;
        for(int i=0;i<=s;i++) pa[i] = i;
    }
    int find(int x) {
        if(x == pa[x]) return x;
        return pa[x] = find(pa[x]);
    }
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        return pa[a] = b,true;
    }
};

vector<edge> g[MAXN],edges;
dsu kruskal;

int dp[MAXN][LOGN],depth[MAXN];
int64_t mx[MAXN][LOGN];
void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
        mx[cur][i] = max(mx[cur][i-1],mx[dp[cur][i-1]][i-1]);
    }
    for(auto nxt : g[cur]) {
        if(nxt.des == from) continue;
        dp[nxt.des][0] = cur;
        mx[nxt.des][0] = (int64_t) nxt.w;
        dfs(nxt.des,cur);
    }
}

int64_t maxLCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int64_t tmp = 0, power = 0;
    while(diff) {
        if(diff & 1) {
            tmp = max(tmp, mx[a][power]);
            a = dp[a][power];
        }
        power++, diff >>= 1;
    }
    if(a == b) return tmp;
    for(int j = LOGN-1
    ;j>=0;j--) {
        if(dp[a][j] == dp[b][j]) continue;
        tmp = max({tmp, mx[a][j], mx[b][j]});
        a = dp[a][j], b = dp[b][j];
    }
    return max({tmp,mx[a][0],mx[b][0]});
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        edges.push_back({a,b,x,i+1});
    }
    kruskal.init(n+5);
    sort(edges.begin(),edges.end(), [&](const edge &A, const edge &B) {
        return A.w < B.w;
    });
    vector<bool> inTree(m+1,0);
    int64_t mst = 0;
    for(auto edge : edges) {
        if(kruskal.merge(edge.src,edge.des)) {
            mst += edge.w;
            g[edge.src].push_back({edge.src,edge.des,edge.w,edge.id});
            g[edge.des].push_back({edge.des,edge.src,edge.w,edge.id});
            // cout << "edge : " << edge.src << ' ' << edge.des << '\n';
            inTree[edge.id];
        }
    }
    dfs(1,1);
    if(depth[n] == 0) cout << -1;
    else cout << maxLCA(1,n);
}