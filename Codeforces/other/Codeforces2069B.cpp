// Problem : https://codeforces.com/contest/2069/problem/B
// Tags : Greedy, BFS
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    int v[705][705], vis[705][705];
    // unordered_map<int, vector<pair<int,int>>> point;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v[i][j];
            vis[i][j] = 0;
        }
    }
    const pair<int,int> dx[] = {{0,1},{0,-1},{1,0},{-1,0}};
    function<int(int,int)> bfs=[&](int x,int y) {
        queue<pair<int,int>> q;
        int node = 0;
        q.push({x,y});
        vis[x][y] = 1;
        while(!q.empty()) {
            node++;
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            for(auto dy : dx) {
                int tx = xx + dy.first;
                int ty = yy + dy.second;
                if(tx>=0&&tx<n&&ty>=0&&ty<m) {
                    if(v[xx][yy] == v[tx][ty] && !vis[tx][ty]) {
                        vis[tx][ty] = 1;
                        q.push({tx,ty});
                    }
                }
            }   
        }
        return node;
    };
    unordered_map<int,int> maxi;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int k = bfs(i,j);
            maxi[v[i][j]] = max(maxi[v[i][j]], k);
        }
    }
    int no, mx = 0;
    for(auto [a,b] : maxi) {
        // cout << a << ' ' << b << '\n';
        if(b > mx) {
            mx = b;
            no = a;
        }
    }
    int ans = 0;
    for(auto [a,b] : maxi) {
        if(a!=no) {
            //cout << a << ' ' << b << '\n';
            ans += min(b, (int)2);
        }
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}