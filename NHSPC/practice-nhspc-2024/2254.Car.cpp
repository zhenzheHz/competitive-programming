// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2021 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2254
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
int n,m,c[MAXN],tc[MAXN];
pair<int,int> edge[MAXN];
bool haveCycle(int P) {
    vector<int> g[MAXN],degree(MAXN,0);
    for(int i=1;i<=m;i++) {
        if(c[i] > P) g[edge[i].first].push_back(edge[i].second);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        cin >> edge[i].first >> edge[i].second;
        cin >> c[i];
        tc[i] = c[i];
    }
    sort(tc+1,tc+m+1);
    int l = 0, r = m+1;
    while(l+1!=r) {
        int mid = (l+r) >> 1;
        if(haveCycle(mid)) l = mid;
        else r = mid;
    }
}