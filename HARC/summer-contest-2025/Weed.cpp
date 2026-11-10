#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+10;
struct Edge {int u,v,w;};
int n;
map<pair<int,int>,int> edge;
struct BIT {
    vector<int> sum;
    BIT() : sum(MAXN,0) {}
    void update(int idx,int x) {
        for(; idx <= n+1;idx += idx&-idx) {
            sum[idx] += x;
        }
    }
    int get(int idx) {
        int ans = 0;
        while(idx) {
            ans += sum[idx];
            idx -= idx&-idx;
        }
        return ans;
    }
};
int depth[MAXN], in[MAXN], out[MAXN];
vector<int> g[MAXN];
vector<Edge> lst;
int timer = 0;
void dfs(int cur,int from) {
    in[cur] = ++timer;
    depth[cur] = depth[from] + 1;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    } 
    out[cur] = timer;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        g[a].push_back(b);
        g[b].push_back(a);
        lst.push_back({a,b,x});
        edge[{a,b}] = edge[{b,a}] = x;
    }
    dfs(1,1);
    BIT ett = BIT();
    ett.update(in[1],0);
    for(auto &[u,v,w] : lst) {
        if(depth[u] > depth[v]) swap(u,v);
        ett.update(in[v],w);
        ett.update(out[v]+1,(-1)*w);
    }
    // for(int i=1;i<=n;i++) cout << in[i] << ' ' << out[i] << '\n';
    int q;
    cin >> q;
    while(q--) {
        int op;
        cin >> op;
        if(op == 0) {
            int x;
            cin >> x;
            cout << ett.get(in[x]) << '\n';
        }else {
            int a,b,x;
            cin >> a >> b >> x;
            int tmp = x;
            if(depth[a] < depth[b]) swap(a,b);
            x -= edge[{a,b}];
            edge[{a,b}] = edge[{b,a}] = tmp;
            ett.update(in[a],x);
            ett.update(out[a]+1,(-1)*x);
        }
    }
    return 0;
}