#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int inf = 1e18+5,N=1e5+5;
struct Edge{
	int u,w;
	bool operator <(const Edge &cmp)const{
		return cmp.w < w;
	}
};
vector<int> dis_1(N,inf),dis_n(N,inf);
vector<vector<Edge>> car(N,vector<Edge>()),walk(N,vector<Edge>());
void dijkstra(vector<vector<Edge>>&lst,vector<int>&dis,int node){
    vector<bool> mark(N,false);
    priority_queue<Edge> pq;
    pq.push({node,0});
    dis.at(node) = 0;
    while(!pq.empty()){
        auto top = pq.top();pq.pop();
        if(mark[top.u]) continue;
        mark[top.u] = true;
        for(auto &edge : lst[top.u]){
            if(top.w + edge.w < dis.at(edge.u)){
                dis.at(edge.u) = top.w + edge.w;
                pq.push({edge.u,top.w + edge.w});
            }
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>park(k);
    for(int &node : park)cin >> node;
    #define pb push_back
    while(m--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        car[a].pb({b,c});
        car[b].pb({a,c});
        walk[a].pb({b,d});
        walk[b].pb({a,d});
    }
    dijkstra(car,dis_1,1);
    dijkstra(walk,dis_n,n);
    int ans = inf;
    for(int &vertex : park){
        ans = min(ans,dis_n[vertex]+dis_1[vertex]);
    }
    cout << ans;
}
