#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int N = 2e5+5;
int E,n,m,q;
vector<int> g[N],degree(N,0);
vector<int> color(N,1);

inline bool is_heavy(int node){
	return degree[heavy] >= E;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	E = sqrt(m);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		degree[a]++,degree[b]++;
	}
	cin >> q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(degree[x] < E){
			//modify
			color[x] = y;
			for(int &near : g[x]){
				color[near] = y;
			}
		}
	}
}
