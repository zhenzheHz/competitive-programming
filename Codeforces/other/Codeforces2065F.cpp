// Problem : https://codeforces.com/contest/2065/problem/F
// Tags : Tree, DFS
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ans(n+1, 0);
    for(int i=1;i<=n;i++) {
        unordered_map<int,int> mark;
        for(int &nxt : g[i]) mark[v[nxt]]++;
        mark[v[i]]++;
        for(auto [val, times] : mark) {
            if(times >= 2) ans[val] = 1;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i];
    return cout<<"\n",void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}