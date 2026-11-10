#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
int a[MAXN];
struct Edge {
    int u,v,w;
    bool operator<(const Edge &cmp) const {
        return w < cmp.w;
    }
};
struct dsu {
    int pa[MAXN];
    void init() {
        for(int i=0;i<MAXN;i++) {
            pa[i] = i;
        }
    }
    int find(int x) {
        if(x == pa[x]) return x;
        return pa[x] = find(pa[x]);
    }
    bool merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return 0;
        return pa[a] = b, 1;
    }
};
vector<Edge> lst;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            lst.push_back({i,j,a[i]^a[j]});
        }
    }
    sort(lst.begin(),lst.end());
    int mst = 0;
    dsu kr;
    kr.init();
    for(auto [u,v,w] : lst) {
        if(kr.merge(u,v)) {
            mst += w;
        }
    }
    cout << mst;
}