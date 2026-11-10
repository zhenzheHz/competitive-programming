// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2254
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
struct Edge { int u,v,w; };
vector<int> g[MAXN];
vector<Edge> lst;
int n,m,u,v,w;
vector<int> change;
bool check(int threshold) {
    for(int i = 0; i < MAXN; i++) g[i].clear();
    change.clear();
    vector<int> degree(MAXN, 0), tp(MAXN, -1);
    for(int i = 0; i < m; i++) {
        if(lst[i].w > threshold) {
            g[lst[i].u].push_back(lst[i].v);
            degree[lst[i].v]++;
        }
    }
    queue<int> q;
    int id = 0;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) {
            q.push(i);
            tp[i] = id++;
        }
    }
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : g[cur]) {
            if(--degree[nxt] == 0) {
                q.push(nxt);
                tp[nxt] = id++;
            }
        }
    }
    if(id != n) return 0;
    for(int i = 0; i < m; i++) {
        auto [u,v,w] = lst[i];
        if(w <= threshold && tp[u] > tp[v]) change.push_back(i+1);
    }
    return 1;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int l = -1, r = -1;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        --u, --v;
        lst.push_back({u,v,w});
        r = max(r, w);
    }
    r++;
    while(l+1 != r) {
        int mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    check(r);
    cout << r << ' ' << (r > 0? change.size() : 0) << '\n';
    if(r > 0) for(auto idx : change) cout << idx << '\n';
    return 0;
}