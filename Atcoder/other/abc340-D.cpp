// Problem : https://atcoder.jp/contests/abc340/tasks/abc340_d
// Tag : Dijkstra
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, INF = 1e18;
struct edge {
    int node, w;
    bool operator<(const edge &cmp) const {
        return w > cmp.w;
    }
};
vector<edge> g[MAXN];
int dp[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        g[i].push_back({i+1,a});
        g[i].push_back({x,b});
    }
    priority_queue<edge> pq;
    pq.push({1,0});
    for(int i=2;i<MAXN;i++) dp[i] = INF;
    dp[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dp[cur.node] < cur.w) continue;
        for(auto nxt : g[cur.node]) {
            if(dp[cur.node] + nxt.w < dp[nxt.node]) {
                dp[nxt.node] = dp[cur.node] + nxt.w;
                pq.push({nxt.node,dp[nxt.node]});
            }
        }
    }
    cout << dp[n];
}