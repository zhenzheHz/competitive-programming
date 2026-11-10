// Problem : https://tioj.ck.tp.edu.tw/problems/2372
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, INF = -1, LOGN = 21;
struct Node {int x,y,z;};
struct Edge {
    int u,v,w;
    bool operator<(const Edge &cmp) const {return w < cmp.w;}
};
struct Dsu {
    int pa[MAXN];
    void init() {
        for(int i=0;i<MAXN;i++) pa[i]= i;
    }
    int find(int x) {return (pa[x] == x? x : pa[x] = find(pa[x]));}
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        return pa[a] = b, 1;
    }
};
const Node dx[6] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
int F,M,N,R,Q;
int id(int x,int y,int z) {return x*M*N+y*N+z;}
bool inRange(int x,int y,int z) {
    return (x>=0 && y>=0 && z >=0 && x<F && y < M && z < N);
}
vector<Edge> g[MAXN],lst;

int depth[MAXN], mn[MAXN][LOGN], dp[MAXN][LOGN];

void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        mn[cur][i] = min(mn[cur][i-1],mn[dp[cur][i-1]][i-1]);
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
    }
    for(auto nxt : g[cur]) {
        if(nxt.v == from) continue;
        dp[nxt.v][0] = cur;
        mn[nxt.v][0] = nxt.w;
        dfs(nxt.v,cur);
    }
}

int query(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int power = 0, tmp_min = 1e18;
    while(diff) {
        if(diff & 1) {
            tmp_min = min(tmp_min, mn[a][power]);
            a = dp[a][power];
        }
        diff >>= 1, power += 1;
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
    cin >> F >> M >> N;
    int dis[MAXN];
    cin >> R;
    memset(dis,INF,sizeof(dis));
    queue<Node> q;
    for(int i=0;i<R;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--, b--, c--;
        q.push({a,b,c});
        dis[id(a,b,c)] = 0;
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0;i<6;i++) {
            int tx = cur.x + dx[i].x;
            int ty = cur.y + dx[i].y;
            int tz = cur.z + dx[i].z;
            if(!inRange(tx,ty,tz)) continue;
            if(dis[id(tx,ty,tz)] != -1) continue;
            dis[id(tx,ty,tz)] = dis[id(cur.x,cur.y,cur.z)] + 1;
            q.push({tx,ty,tz});
        }
    }
    for(int i=0;i<F;i++) for(int j=0;j<M;j++) for(int k=0;k<N;k++) {
        for(int dir = 0;dir < 6; dir ++) {
            int tx = i + dx[dir].x;
            int ty = j + dx[dir].y;
            int tz = k + dx[dir].z;
            if(!inRange(tx,ty,tz)) continue;
            int id1 = id(i,j,k), id2 = id(tx,ty,tz);
            lst.push_back({id1,id2,min(dis[id1],dis[id2])});
        }
    }
    sort(lst.rbegin(),lst.rend());
    Dsu kru;
    kru.init();
    int mst = 0;
    for(int i=0;i<(int) lst.size();i++) {
        auto [u,v,w] = lst[i];
        if(kru.merge(u,v)) {
            mst += w;
            g[u].push_back({u,v,w});
            g[v].push_back({v,u,w});
        }
    }
    dfs(0,0);
    cin >> Q;
    while(Q--) {
        int a,b,c,x,y,z;
        cin >> a >> b >> c >> x >> y >> z;
        a--, b--, c--, x--, y--, z--;
        if(a == x && b == y && c == z) cout << dis[id(a,b,c)] << '\n';
        else cout << query(id(a,b,c),id(x,y,z)) << '\n';
    }
}