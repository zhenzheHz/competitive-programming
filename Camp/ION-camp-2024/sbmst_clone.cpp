#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int N = 2e5+5;
struct Edge{
	int from,to,w;
	bool used = false;
	bool operator<(const Edge &cmp)const{
		return w < cmp.w;
	}
};

int n,m,logN;
vector<int> pa(N,-1),depth(N,0),dp,dis;
vector<Edge> g[N],lst;
//==========DSU=============
inline int find(int x){
	if(x == pa[x])return x;
	return pa[x] = find(pa[x]);
}

inline bool merge(int a,int b){{
	a = find(a),b = find(b);
	if(a == b)return false;
	pa[a] = b;
	return true;
}
//=========Kruskal=========
inline int Minimum_Spanning_Tree(){
	sort(lst.begin(),lst.end());
	int node = 0,sum = 0;
	for(auto &edge : lst){
		if(merge(edge.from,edge.to)){
			node++;
			sum += edge.w;
			edge.used = true;
			g[edge.from].push_back({edge.from,edge.to,edge.w,true});
			g[edge.to].push_back({edge.to,edge.from,edge.w,true});
		}
	}
	if(node == n-1)return sum;
	else return -1;
}
//========dfs build table=======
inline void dfs(int cur,int from){
	depth[cur] = depth[from] + 1;
	for(int i=1;i<=logN;i++){
		dp[cur][j] = dp[dp[cur][j-1]][j-1];
		dis[cur][j] = max(dis[cur][j-1],dis[dp[cur][j-1]]][j-1]);
	}
	for(auto &nxt : g[cur]){
		if(nxt.to == from)continue;
		dp[nxt.to][0] = cur;
		dis[nxt.to][0] = nxt.w;
	}
}
//===========find max weight edge============
inline int max_weight_edge(int a,int b){
	if(depth[a] < depth[b])swap(a,b);
	int diff = depth[a] - depth[b];
	int result = 0;
	for(int i=logN;i>=0;i--){
		if((1<<i) <= diff){
			result = max(result,dp[a][i]);
			diff -= (1<<i);
			a = dp[a][i];
		}
	}
	for(int i=logN;i>=0;i--){
		if(dp[a][i] == dp[b][i])continue;
		result = max({result,dis[a][i],dis[b][i]}]);
		a = dp[a][i];
		b = dp[b][i];
	}
	return max({result,dis[a][0],dis[b][0]});
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)pa[i] = i;
	dis.resize(N,vector<int>(logN+1,1e18));
	dp.resize(N,vector<int>(logN+1,0));
	while(m--){
		int a,b,x;
		cin>>a>b>>x;
		lst.push_back(a,b,x,false);
	}
	int mst = Minimum_Spanning_Tree();
	cout << mst << ' ';
	if(mst == -1 || m+1 == n){
		cout << -1;return 0;
	}
	int sbmst = 1e18;
	for(auto &edge : lst){
		if(edge.used)continue;
		int tmp = mst - max_weight_edge(edge.from,edge.to) + edge.w;
		if(tmp == mst)continue;
		sbmst = min(sbmst,tmp);
	}
	cout << sbmst;
}
