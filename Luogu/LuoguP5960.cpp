// Problem : https://www.luogu.com.cn/problem/P5960
// Tag : 差分約束(Bellman-Ford)
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Edge{int u,v,w;};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<Edge> lst;
    for(int i=1;i<=n;i++) {
        lst.push_back({0,i,0});
    }
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        lst.push_back({b,a,c});
    }
    vector<int> dis(n+1,(int)1e18);
    dis[0] = 0;
    for(int i=1;i<n;i++) {
        for(auto edge : lst) {
            dis[edge.v] = min(dis[edge.v],dis[edge.u] + edge.w);
        }
    }
    for(auto edge : lst) {
        if(dis[edge.v] > dis[edge.u] + edge.w) {
            return cout<< "NO\n",0;
        }
    }
    for(int i=1;i<=n;i++) cout << dis[i] << " \n"[i==n];
    return 0;
}