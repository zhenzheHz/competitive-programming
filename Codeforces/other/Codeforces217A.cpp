// Problem : https://codeforces.com/problemset/problem/217/A
#include <bits/stdc++.h>
using namespace std;
struct Dsu {
    int cnt;
    vector<int> pa;
    void init(int n) {
        pa.resize(n+1);
        cnt = n;
        for(int i = 0; i <= n; i++) {
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
        pa[a] = b;
        return cnt--, 1;
    }
    int get() { return cnt; }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    Dsu dsu;
    dsu.init(n);
    vector<pair<int,int>> p(n);
    for(auto &[x,y] : p) {
        cin >> x >> y;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].first == p[j].first) {
                dsu.merge(i,j);
            }
            if(p[i].second == p[j].second) {
                dsu.merge(i,j);
            }
        }
    }
    return cout << dsu.get() - 1, 0;
}