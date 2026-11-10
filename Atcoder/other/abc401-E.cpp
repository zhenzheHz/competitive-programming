// Problem : https://atcoder.jp/contests/abc401/tasks/abc401_e
// Tags : DSU
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;

struct Dsu {
    size_t Size;
    vector<int> pa, sz;
    Dsu(size_t _n) : Size(_n) {
        pa.resize(_n + 1);
        sz.resize(_n + 1, 1);
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) {
        return (x == pa[x]? x : pa[x] = find(pa[x]));
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        pa[a] = b;
        sz[b] += sz[a];
    }
    int size(int x) {
        return sz[find(x)];
    }
};

vector<int> G[MAXN], cnt(MAXN, 0);

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Dsu dsu = Dsu(n);
    int del = 0;
    for(int k = 1; k <= n; k++) {
        if(cnt[k]) del--;
        for(auto node : G[k]) {
            if(node <= k) {
                dsu.merge(node, k);
            }
            else {
                if(cnt[node]++ == 0) del++;
            }
        }
        cout << (dsu.size(1) == k? del : -1);
        cout << '\n';
    }
    return 0;
}