// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2257
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
vector<int> g[MAXN],in(MAXN<<1,0),out(MAXN<<1,0);
struct Edge { int u,v; };
struct BIT {
    int sum[MAXN<<1];
    BIT() { memset(sum,0,sizeof(sum)); }
    #define lowbit(x) (x&-x)
    void update(int idx,int x) {
        for(int i = idx; i <= (MAXN<<1); i += lowbit(i)) {
            sum[i] += x;
        }
    }
    int query(int v) {
        int result = 0;
        while(v > 0) {
            result += sum[v];
            v -= lowbit(v);
        }
        return result;
    }
};

BIT route = BIT();
int n,s,t,w,x,y,timer = 0;
vector<Edge> lst;

void dfs(int cur, int from) {
    in[cur] = ++timer;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    }
    out[cur] = ++timer;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> s >> t >> w;
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        lst.push_back({x,y});
    }
    dfs(s,s);
    for(int i = 1; i <= n; i++) {
        if(i != s) {
            route.update(in[i], 1);
            route.update(out[i], -1);
        }
    }
    for(int i = 0; i < t + w; i++) {
        int op;cin >> op;
        if(op == 1) {
            cin >> x >> y;
            cout << x * route.query(in[y]) << '\n';
        }
        else {
            cin >> x;
            auto [u,v] = lst[x-1];
            int vertex = (in[u] > in[v]? u : v);
            route.update(in[vertex], -1);
            route.update(out[vertex], 1);
        }
    }
    return 0;
}