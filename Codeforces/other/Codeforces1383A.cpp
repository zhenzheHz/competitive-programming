// Problem : https://codeforces.com/contest/1383/problem/A
// Tags : Reduction
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MAXN = 't' - 'a' + 1;

void dfs(vector<vector<int>> &g, vector<int> &vis, int cur) {
    vis[cur] = 1;
    for(int x : g[cur]) {
        if(!vis[x]) dfs(g,vis,x);
    }
}

void solve() {
    int n;
    cin >> n;
    string A,B;
    cin >> A >> B;
    vector<vector<int>> g(MAXN);
    for(int i=0;i<n;i++) {
        if(A[i] == B[i]) continue;
        if(A[i] > B[i]) return cout<<-1<<'\n',void();
        g[A[i] - 'a'].push_back(B[i] - 'a');
        g[B[i] - 'a'].push_back(A[i] - 'a');
    }
    vector<int> vis(MAXN, 0);
    int ans = MAXN;
    for(int i=0;i<MAXN;i++) {
        if(!vis[i]) {
            dfs(g,vis,i); 
            ans--;
        }
    }
    return cout<<ans<<'\n',void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}