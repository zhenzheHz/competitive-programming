// Problem : https://atcoder.jp/contests/dp/tasks/dp_g
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...);}
template<typename... T>
void send(T&&... args) { ((cout << args << " "), ...);cout<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

int32_t main(){
    fastio;
    int n,m;cin>>n>>m;
    vector<int> g[n+1];
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<int> dis(n+1,0);
    queue<int> q;
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int &nxt : g[cur]){
            q.push(nxt);
            dis[nxt] = max(dis[nxt],dis[cur]+1);
        }
    }
    cout << dis[n];
}