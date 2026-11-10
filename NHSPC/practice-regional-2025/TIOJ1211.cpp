// Problem : https://tioj.ck.tp.edu.tw/problems/1211
// Tags : Minimum Spanning Tree
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5, MAXM = 1e6+5;
struct disjoint_set {
    size_t n;
    int pa[MAXN];
    void init(int _n) {
        n = _n;
        for(int i=0;i<=_n;i++) pa[i]=i;
    }
    int find(int x) {
        return (x == pa[x]? x : pa[x] = find(pa[x]));
    }
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        return pa[a] = b, 1;
    }
};
struct Edge {
    int src,des,w;
    bool operator<(const Edge &cmp) const {
        return w < cmp.w;
    }
};
int mst(int n,int m) {
    disjoint_set dsu;
    dsu.init(n);
    vector<Edge> edges(m);
    for(auto &eg : edges) {
        cin >> eg.src >> eg.des >> eg.w;
    }
    sort(edges.begin(),edges.end());
    int sum = 0, node = 0;
    for(auto &edge : edges) {
        if(dsu.merge(edge.src, edge.des)) {
            sum += edge.w;
            node += 1;
        }
    }
    return (node == n-1? sum : -1);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m) {
        if(n + m == 0) break;
        cout << mst(n,m) << '\n';
    }
    return 0;
}