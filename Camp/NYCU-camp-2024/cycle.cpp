#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int N = 1e5+5;
int start;
vector<int> adj[N],vis(N,0),path;
bool dfs(int node,int from){
    if(vis[node]){start = node;return true;}
    path.push_back(node);
    vis[node] = 1;
    for(int &u : adj[node]){
        if(u == from)continue;
        bool cycle = dfs(u,node);
        if(cycle)return true; 
    }
    path.pop_back();
    return false;
}
int32_t main(){
    int n,m;cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        path.clear();  
        bool valid = dfs(i,i);
        if(!valid)continue;
        vector<int>ans;
        bool find = false;
        cout << "YES\n";
        for(int &node : path){
            if(node == start)find = true;
            if(find)ans.push_back(node);
        }
        ans.push_back(start);
        cout << ans.size() << '\n';
        for(int &node : ans){
            cout << node << ' ';
        }
        return 0;
    }
    cout << "NO";
}
