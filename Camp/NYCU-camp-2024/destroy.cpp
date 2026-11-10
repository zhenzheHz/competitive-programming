#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct DSU{
    int _size;
    vector<int> parent;
    void init(int _n){
        _size = _n;
        parent.resize(_size+1);
        for(int i=0;i<=_size;i++)
            parent[i] = i;
    }
    int find(int x){
        if(x == parent[x])return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int a,int b){
        a = find(a),b = find(b);
        if(a == b)return;
        parent[b] = a;
        _size -= 1;
    }
    int getCount(){
        return _size;
    }
};
int32_t main(){
    int n,m,k;cin>>n>>m>>k;
    DSU dsu;
    dsu.init(n);
    vector<pair<int,int>> edges(m),destroy(k);
    set<pair<int,int>> dset; 
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        edges[i] = {a,b}; 
    }
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        destroy[i] = {a,b};
        dset.insert({a,b});
    }
    for(auto &edge : edges){
        if(dset.find(edge) != dset.end())continue;
        if(dset.find({edge.second,edge.first}) != dset.end())continue;
        dsu.merge(edge.first,edge.second);
    }
    vector<int> ans(k);
    for(int i=k-1;i>=0;i--){
        ans[i] = dsu.getCount();
        auto edge = destroy[i];
        dsu.merge(edge.first,edge.second);
    }
    for(int &answer : ans){
        cout << answer << ' ';
    }
}
