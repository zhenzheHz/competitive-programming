// Problem : https://codeforces.com/contest/2065/problem/D
// Tags : Greedy, Sorting
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct perm {
    int sigma = 0, sum = 0;
    vector<int> v;
    void input(int x) {
        v.resize(x);
        for(int &x : v) cin >> x;
        for(int i=0;i<x;i++) {
            sum += v[i];
            sigma += v[i] * (x-i);
        }
    }
};
void solve() {
    int n,m;
    cin >> n >> m;
    vector<perm> grid(n);
    for(int i=0;i<n;i++) {
        grid[i].input(m);
    }
    sort(grid.begin(),grid.end(),[&](const perm &a, const perm &b) {
        return a.sum > b.sum;
    });
    int ans = 0;
    for(int i=0;i<n;i++) {
        // cout << grid[i].sigma << '\n';
        // for(int x : grid[i].v) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        ans += m * (n-i-1) * grid[i].sum + grid[i].sigma;
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}