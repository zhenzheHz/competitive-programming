// Problem : https://codeforces.com/contest/1625/problem/A
// Tags : Bitmask, Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n), bit(m);
    for(int &x : v) {
        cin >> x;
        for(int j=0;j<m;j++) {
            if((x >> j) & 1) bit[j] += 1;
            else bit[j] -= 1;
        }
    }
    int ans = 0;
    for(int i=0, p = 1; i<m; i++, p <<= 1) {
        ans += p * (bit[i] > 0);
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}