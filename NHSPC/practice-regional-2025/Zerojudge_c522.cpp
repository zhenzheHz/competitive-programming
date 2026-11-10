// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c522
// Tag : 2017 高雄市 資訊學科能力 複賽 7
// Note : 遞迴深度過深，要改 BFS 才會 AC
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e5+5, LOGN = 20;
struct Query {
    int u,v,tag;
};
struct Dsu {
    vector<int> pa;
    void init(size_t k) {
        pa.resize(k);
        for(int i=0;i<k;i++) pa[i] = i;
    }
    int find(int x) {
        return (x == pa[x]? x : pa[x] = find(pa[x]));
    }
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return 1;
        return pa[a] = b, 0;
    }
};
int N,M;
Dsu unite;
vector<vector<pair<int,int>>> g;
vector<int> depth;
vector<vector<int>> dp,mx;
void dfs(int cur, int from) {
    depth[cur] = depth[from] + 1; 
    dp[cur][0] = from;
    for(int j = 1; j < LOGN; j++) {
        dp[cur][j] = dp[dp[cur][j-1]][j-1];
        mx[cur][j] = max(mx[cur][j-1], mx[dp[cur][j-1]][j-1]);
    }
    for(auto [nxt, w] : g[cur]) {
        if(nxt == from) continue;
        dp[nxt][0] = cur;
        mx[nxt][0] = w;
        dfs(nxt, cur);
    }
}
int LCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int power = 0, tmp = 0;
    while(diff) {
        if(diff & 1) {
            tmp = max(tmp, mx[a][power]);
            a = dp[a][power];
        }
        power += 1, diff >>= 1;
    }
    if(a == b) return tmp;
    for(int j = LOGN-1; j >= 0; j--) {
        if(dp[a][j] == dp[b][j]) continue;
        tmp = max({tmp, mx[a][j], mx[b][j]});
        a = dp[a][j], b = dp[b][j];
    }
    return max({tmp, mx[a][0], mx[b][0]});
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> N >> M;
    unite.init(N+1);
    g.resize(N+1);
    depth.resize(N+1, 0);
    dp.resize(N+1, vector<int> (LOGN+1, 0));
    mx.resize(N+1, vector<int> (LOGN+1, 0));
    vector<Query> query(M);
    for(int i = 0; i < M; i++) {
        int x,y,tag;
        cin >> x >> y;
        tag = unite.merge(x,y);
        query[i] = {x,y,tag};
        if(!tag) {
            g[x].push_back({y,i+1});
            g[y].push_back({x,i+1});
        }
    }
    for(int i = 1; i <= N; i++) {
        if(unite.find(i) == i) {
            dp[i][0] = 0;
            depth[i] = 0;
            mx[i][0] = 0;
            dfs(i,i);
        }
    }
    for(auto [x,y,un] : query) {
        if(!un) cout << "Mukyu\n";
        else cout << LCA(x,y) << '\n';
    }
    return 0;
}