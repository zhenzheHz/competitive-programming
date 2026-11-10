// Problem : https://atcoder.jp/contests/abc385/tasks/abc385_e
// Tags : Construct
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> degree(n+1,0), adj[n+1];
    for(int i=1;i<n;i++) {
        int src, des;
        cin >> src >> des;
        adj[src].push_back(des);
        adj[des].push_back(src);
        degree[src] += 1;
        degree[des] += 1;
    }
    int ans = 1e18;
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(),adj[i].end(),[&](const int a,const int b) {
            return degree[a] > degree[b];
        });
    }
    for(int i=1;i<=n;i++) {
        int x = 0, y;
        for(int &nxt : adj[i]) {
            x += 1, y = degree[nxt] - 1;
            ans = min(ans,n - 1 - x - x*y);
        }
    }
    return cout << ans << '\n',0;
}