// Problem : https://codeforces.com/contest/2065/problem/C1
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m,b;
    cin >> n >> m;
    vector<int> v(n), tr(n);
    for(int &x : v) cin >> x;
    cin >> b;
    for(int i=0;i<n;i++) tr[i] = b - v[i];
    vector<int> now;
    now.push_back(min(v[0], tr[0]));
    for(int i=1;i<n;i++) {
        int r = v[i], s = tr[i];
        if(r < now.back() && s < now.back())
            return cout<<"NO\n",void();
        if(r < now.back()) now.push_back(s);
        else if(s < now.back()) now.push_back(r);
        else now.push_back(min(r,s));
    }
    return cout << "YES\n",void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}