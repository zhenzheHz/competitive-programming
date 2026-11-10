// Problem : https://atcoder.jp/contests/abc393/tasks/abc393_c
// Tags : STL
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,ans = 0;
    cin >> n >> m;
    set<pair<int,int>> edges;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        ans += (a != b && edges.find({a,b}) != edges.end());
        ans += (a == b);
        edges.insert({a,b});
        edges.insert({b,a});
    }
    return cout<<ans,0;
}