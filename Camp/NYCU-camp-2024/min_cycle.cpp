#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<int> g[n+1];
    while(m--){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = INT_MAX;
    // int test = 1;
    for(int i=1;i<=n;i++){
        vector<int> vis(n+1,-1);
        vis[i] = 0;
        queue<pair<int,int>> q;
        //node ,from
        q.push({i,-1});
        while(!q.empty()){
            auto node = q.front();q.pop();
            int v = node.first,p = node.second;
            for(int &u : g[v]){
                if(u == p)continue;
                if(vis[u] != -1){
                    ans = min(ans,vis[v] + vis[u] + 1);
                    // cerr << test++ << ":" << i  << ' ' << v << ' ' << u << ' ' << ans <<'\n';
                }else{
                    vis[u] = vis[v] + 1;
                    q.push({u,v});
                }
            }
        }
    }
    if(ans == INT_MAX)cout << -1;
    else cout << ans;
}
