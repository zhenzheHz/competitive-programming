// Problem : https://codeforces.com/contest/1593/problem/E
// Tags : Topological Sort, BFS
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> g[n+1], degree(n+1,0), remove(n+1,0);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++, degree[b]++;
    }
    queue<int> topo;
    for(int i=1;i<=n;i++) {
        if(degree[i] == 1) {
            topo.emplace(i);
            remove[i] = 1;
        }
    }
    while(!topo.empty()) {
        int cur = topo.front();
        topo.pop();
        for(int &nxt : g[cur]) {
            if(degree[nxt] != 1 && --degree[nxt] == 1) {
                topo.push(nxt);
                remove[nxt] = remove[cur] + 1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans += (remove[i] > k);
    }
    return cout<<ans<<'\n',void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}