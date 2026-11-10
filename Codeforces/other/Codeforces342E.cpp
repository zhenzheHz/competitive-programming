// Problem : https://codeforces.com/contest/342/problem/E
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5,LOGN = 21;
int n,q;
vector<int> g[MAXN];
bool red[MAXN];
int ans[MAXN],depth[MAXN],dp[MAXN][LOGN];
void dfs(int cur,int from) {
    depth[cur] = depth[from] + 1;
    dp[cur][0] = from;
    for(int i=1;i<LOGN;i++) {
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
    }
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
    }
}
int LCA(int a,int b) {
    if(depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];
    int power = 0;
    while(diff) {
        if(diff & 1) a = dp[a][power];
        diff >>= 1;
        power += 1;
    }
    if(a == b) return a;
    for(int j=LOGN-1;j>=0;j--) {
        if(dp[a][j] == dp[b][j]) continue;
        a = dp[a][j], b = dp[b][j];
    }
    return dp[a][0];
}
void update() {
    queue<int> q;
    for(int i=0;i<MAXN;i++) ans[i] = -1;
    for(int i=1;i<=n;i++) {
        if(red[i]) {
            q.push(i);
            ans[i] = 0;
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto nxt : g[cur]) {
            if(ans[nxt] == -1) {
                ans[nxt] = ans[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> q;
    red[1] = 1, ans[1] = 0;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    update();
    const int thr = sqrt(q);
    vector<int> buff;
    while(q--) {
        int op,x;
        cin >> op >> x;
        if(op == 1) {
            red[x] = 1;
            buff.push_back(x);
        } else {
            int tmp = ans[x];
            for(auto fix : buff) {
                int dis = depth[x] + depth[fix] - 2 * depth[LCA(x,fix)];
                tmp = min(tmp, dis);
            }
            cout << tmp << '\n';
        }
        if((int)buff.size() >= thr) {
            buff.clear();
            update();
        }
    }
}