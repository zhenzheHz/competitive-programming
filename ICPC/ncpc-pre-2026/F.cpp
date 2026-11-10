#include<bits/stdc++.h>
using namespace std;
int n;
// #define int int64_t
int mark[1010][310][310] = {};
// vector<vector<vector<int>>>mark(1010, vector<vector<int>>(310, vector<int>(310, -1)));
vector<pair<int, int>>f;
inline int check(int x, int t, int k) {
    if(t < 0 || k < 0) return -1;
    if(x == n) return 0;
    if(mark[x][t][k] != -1) return mark[x][t][k];

    int l = check(x + 1, t - f[x].first, k - f[x].second) + 1;
    int r = check(x + 1, t, k);

    return mark[x][t][k] = max({l, r});
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0;i<1010;i++) for(int j = 0;j<310;j++) for(int k = 0;k<310;k++) mark[i][j][k] = -1;

    int a, b, c;cin>>a>>b>>c;
    n = a;

    b = b >> 1;
    
    f = vector<pair<int, int>>(n);
    for(auto &i : f) cin>>i.first>>i.second;

    // for(auto &i : f) if(i.second == 0) i.first = 0;

    cout<<check(0, b, c);
    return 0;
}