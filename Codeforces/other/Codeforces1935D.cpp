// Problem : https://codeforces.com/contest/1935/problem/D
// Tags : Math
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,c;
    cin >> n >> c;
    vector<int> v(n);
    int ans = (c + 1) * (c + 2) / 2;
    int odd = 0, even = 0;
    for(int &s : v) {
        cin >> s;
        ans -= s / 2 + 1;
        ans -= c - s + 1;
        odd += (s & 1);
        even += (!(s & 1));
    }
    ans += odd * (odd + 1) / 2;
    ans += even * (even + 1) / 2;
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}