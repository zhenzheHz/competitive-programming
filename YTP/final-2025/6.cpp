#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
vector<int> g[MAXN];
int depth[MAXN],ans[MAXN];
void dfs(int cur,int from) {
    if(cur!=1) depth[cur] = depth[from] + 1;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    
}