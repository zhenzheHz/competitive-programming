// Problem : https://codeforces.com/contest/1625/problem/A
// Tags : Binary Search, Graph
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> g[n+1];
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    function<bool(int)> check = [&](int x) {
        int total_cut = 0;
        function<int(int,int)> dfs = [&](int cur, int from) {
            int SIZE = 1;
            for(auto nxt : g[cur]) {
                if(nxt == from) continue;
                SIZE += dfs(nxt, cur);
            }
            if(SIZE >= x) total_cut += 1, SIZE = 0;
            return SIZE;
        };
        int root = dfs(1,-1);
        return total_cut > k || (total_cut == k && root >= x);
    };
    int l = -1, r = n+1;
    while(l+1!=r) {
        int m = (l+r)>>1;
        if(check(m)) l = m;
        else r = m;
    }
    return cout<<l<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}