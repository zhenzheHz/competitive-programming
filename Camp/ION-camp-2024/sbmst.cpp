#include <bits/stdc++.h>
#define int int64_t 
using namespace std;
#define emplace_back push_back
struct Edge{
    int from,to,w;
    bool used = false;
    bool operator<(const Edge& cmp)const{
        return w < cmp.w;
    }
};

static constexpr int N = 1e3+5;
int n,m,logN;

vector<Edge> g[N],lst;
vector<int> pa(N,-1),depth(N,0);
vector<vector<int>> dp,dis;

inline int find(int x){
    if(x == pa[x])return x;
    return pa[x] = find(pa[x]);
}

inline bool merge(int a,int b){
    a = find(a),b = find(b);
    if(a == b)return false;
    pa[a] = b;
    return true;
}

inline int MST(){
    sort(lst.begin(),lst.end());
    int node = 0,sum = 0;
    for(auto &edge : lst){
        if(merge(edge.from,edge.to)){
            sum += edge.w;
            node += 1;
            //save the graph
            g[edge.from].emplace_back({edge.from,edge.to,edge.w,true});
            g[edge.to].emplace_back({edge.to,edge.from,edge.w,true});
            edge.used = true;
        }
    }
    if(node != n-1)return -1;
    return sum;
}

inline void dfs(int cur,int from){
    depth[cur] = depth[from] + 1;
    for(int j=1;j<=logN;j++){
        dp[cur][j] = dp[dp[cur][j-1]][j-1];
        dis[cur][j] = max(dis[cur][j-1],dis[dp[cur][j-1]][j-1]);
    }
    for(auto &nxt : g[cur]){
        if(nxt.to == from)continue;
        dp[nxt.to][0] = cur;
        dis[nxt.to][0] = nxt.w;
        dfs(nxt.to,cur);
    }
}

inline int max_weight_edge(int a,int b){
    if(depth[a] < depth[b])swap(a,b);
    int diff = depth[a]-depth[b];
    int result = 0;
    //jump to same depth
    for(int i=logN;i>=0;i--){
        if(diff >= (1<<i)){
            diff -= (1<<i);
            result = max(result,dis[a][i]);
            a = dp[a][i];
        }
    }
    if(a == b)return result;
    for(int p=logN;p>=0;p--){
        if(dp[a][p] == dp[b][p])continue;
        result = max({result,dis[a][p],dis[b][p]});
        a = dp[a][p];
        b = dp[b][p];
    }
    return max({result,dis[a][0],dis[b][0]});
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    logN = __lg(n);
    dp.resize(N,vector<int>(logN+1,0));
    dis.resize(N,vector<int> (logN+1,-1));
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        lst.emplace_back({a,b,x,false});
    }
    for(int i=1;i<=n;i++){
        pa[i] = i;
    }
    int mst = MST();
    cout << mst << ' ';
    if(n == m+1 || mst == -1){
        //edges fully used
        cout << -1;
        return 0;
    }
    dfs(1,0);
    int sbmst = 1e18+5;
    for(auto &edge : lst){
        if(edge.used)continue;
        int tmp = mst - max_weight_edge(edge.from,edge.to) + edge.w;
        if(tmp == mst)continue;
        sbmst = min(sbmst,tmp);
    }
    if(sbmst == 1e18+5)cout << -1;
    else cout << sbmst;
}