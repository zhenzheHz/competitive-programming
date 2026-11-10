// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2021 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2257
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+10;
int n,s,t,w,bit[MAXN],in[MAXN],out[MAXN];
pair<int,int> edge[MAXN];
vector<int> g[MAXN];
void update(int p,int x) {
    while(p <= n*2) {
        bit[p] += x;
        p += p&-p;
    }
}
int query(int p) {
    int sum = 0;
    while(p > 0) {
        sum += bit[p];
        p -= p&-p;
    }
    return sum;
}
int timer = 1;
void dfs(int cur,int from) {
    in[cur] = timer++;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    }
    out[cur] = timer++;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> s >> t >> w;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        edge[i] = {a,b};
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(s,s);
    for(int i=1;i<=n;i++) {
        if(i == s) continue;
        update(in[i], 1);
        update(out[i], -1);
        // cout << i << ' ' << in[i] << ' ' << out[i] << '\n';
    }
    for(int i=0;i<t+w;i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x,y;
            cin >> x >> y;
            cout << query(in[y]) * x << '\n';
        }else {
            int p;
            cin >> p;
            // update(in[edge[p].first], -query(in[edge[p].first]));
            // update(out[edge[p].first], -query(out[edge[p].first]));
            int node = in[edge[p].first] > in[edge[p].second]? edge[p].first : edge[p].second;
            update(in[node], -1);
            update(out[node], 1);
        }
    }
}