// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2372
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, LOGN = 18;
#define inRange(i,j,k) (i>=0&&j>=0&&k>=0&&i<F&&j<M&&k<N)
#define id(i,j,k) (i*M*N+j*N+k)
struct Point {int x,y,z;};
struct Edge {
    int u,v,w;
    bool operator<(const Edge &cmp) const {
        return w > cmp.w;
    }
};
struct Dsu {
    int pa[MAXN];
    void init() { iota(pa,pa+MAXN,0); }
    int find(int x) { return (x == pa[x]? pa[x] : pa[x] = find(pa[x])); }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        return pa[a] = b, 1;
    }
};
const Point dxyz[] = {{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
const Point pos_d[] = {{1,0,0},{0,1,0},{0,0,1}};
vector<Edge> lst, KTree[MAXN];
int depth[MAXN], dp[MAXN][LOGN], min_dis[MAXN][LOGN];
void dfs(int cur, int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int j = 1; j < LOGN; j++) {
        dp[cur][j] = dp[dp[cur][j-1]][j-1];
        min_dis[cur][j] = min(min_dis[cur][j-1], min_dis[dp[cur][j-1]][j-1]);
    }
    for(auto [u,nxt,w] : KTree[cur]) {
        if(nxt == from) continue;
        dp[nxt][0] = cur;
        min_dis[nxt][0] = w;
        dfs(nxt,cur);
    }
}
int findLCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int tmp = 1e18;
    int diff = depth[a] - depth[b], power = 0;
    while(diff) {
        if(diff & 1) {
            tmp = min(tmp,min_dis[a][power]);
            a = dp[a][power];
        }
        diff >>= 1, power += 1;
    }
    if(a == b) return tmp;
    for(int j = LOGN-1; j >= 0; j--) {
        if(dp[a][j] == dp[b][j]) continue;
        tmp = min({tmp,min_dis[a][j],min_dis[b][j]});
        a = dp[a][j], b = dp[b][j];
    }
    return min({tmp,min_dis[a][0],min_dis[b][0]});
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int F,M,N,R,Q;
    cin >> F >> M >> N;
    int dis[F][M][N];
    cin >> R;
    fill(&dis[0][0][0], &dis[0][0][0]+F*M*N, -1);
    queue<Point> q;
    for(int i = 0; i < R; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        --x, --y, --z;
        q.push({x,y,z});
        dis[x][y][z] = 0;
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto [dx,dy,dz] : dxyz) {
            int tx = cur.x + dx;
            int ty = cur.y + dy;
            int tz = cur.z + dz;
            if(!inRange(tx,ty,tz) || dis[tx][ty][tz] != -1) continue;
            q.push({tx,ty,tz});
            dis[tx][ty][tz] = dis[cur.x][cur.y][cur.z] + 1;
        }
    }
    for(int i = 0; i < F; i++) for(int j = 0; j < M; j++) {
        for(int k = 0; k < N; k++) {
            for(auto [dx,dy,dz] : pos_d) {
                int tx = i + dx, ty = j + dy, tz = k + dz;
                if(!inRange(tx,ty,tz)) continue;
                lst.push_back({id(i,j,k), id(tx,ty,tz), min(dis[i][j][k], dis[tx][ty][tz])});
            } 
        }
    }
    sort(lst.begin(), lst.end());
    Dsu dsu;
    dsu.init();
    for(auto [u,v,w] : lst) {
        if(dsu.merge(u,v)) {
            KTree[u].push_back({u,v,w});
            KTree[v].push_back({v,u,w});
        }
    }
    dfs(0,0);
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int sx,sy,sz,ex,ey,ez;
        cin >> sx >> sy >> sz >> ex >> ey >> ez;
        --sx, --sy, --sz, --ex, --ey, --ez;
        if(sx == ex && sy == ey && sz == ez) cout << dis[sx][sy][sz] << '\n';
        else cout << findLCA(id(sx,sy,sz),id(ex,ey,ez)) << '\n';
    }
    return 0;
}