// Problem : https://codeforces.com/contest/300/problem/B
// Tags : Greedy, Implement, Graph
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<int> g[50], vis(50,0);

vector<vector<vector<int>>> group(4);
vector<int> node;

void dfs(int cur) {
    vis[cur] = 1;
    node.push_back(cur);
    for(int &nxt : g[cur]) {
        if(!vis[nxt]) dfs(nxt);
    }   
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    while(m--) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        node.clear();
        dfs(i);
        if(node.size() > 3) return cout<<-1,0;
        int x = node.size();
        group[x].push_back(node);
    }
    if(group[1].size() < group[2].size()) return cout<<-1,0;
    if((group[1].size() - group[2].size()) % 3 != 0) return cout<<-1,0;
    for(auto v : group[3]) {
        for(int i=0;i<3;i++)
            cout << v[i] << " \n"[i==2];
    }
    int idx = 0;
    for(auto v : group[2]) {
        cout << v[0] << ' ' << v[1] << ' ' << group[1][idx++][0] << '\n';
    }
    for(int i=idx;i<group[1].size();i+=3) {
        for(int j=0;j<3;j++) {
            cout << group[1][i+j][0] << " \n"[j==2];
        }
    }
}