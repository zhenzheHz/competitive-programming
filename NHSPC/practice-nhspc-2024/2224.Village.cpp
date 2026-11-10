// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2020 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2224
#include <bits/stdc++.h>
#define int int64_t
#define des first
#define w second
using namespace std;
static constexpr int MAXN = 1e5+5, INF = 1e18+5;
int n,m,degree[MAXN],dis[MAXN];
vector<pair<int,int>> g[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) dis[i] = INF;
    for(int i=0;i<m;i++) {
        int a,b,x;
        cin >> a >> b >> x;
        g[a].push_back({b,x});
        degree[b]++;
    }
    queue<int> tp;
    for(int i=1;i<=n;i++) {
        if(degree[i] == 0)
            tp.emplace(i);
    }
    vector<int> sorted;
    while(!tp.empty()) {
        int cur = tp.front();
        tp.pop();
        sorted.push_back(cur);
        for(auto nxt : g[cur]) {
            if(--degree[nxt.des] == 0) {
                tp.emplace(nxt.des);
            }
        }
    }
    assert(sorted.size() == n);
    dis[1] = 0;
    for(int &node : sorted) {
        for(auto nxt : g[node]) {
            dis[nxt.des] = min(dis[nxt.des], dis[node] + nxt.w);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += dis[i];
    cout << ans << '\n';
}