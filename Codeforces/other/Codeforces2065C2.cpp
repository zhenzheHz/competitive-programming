// Problem : https://codeforces.com/contest/2065/problem/C2
// Tags : Binary Search
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> A(n),B(m);
    for(int &x : A) cin >> x;
    for(int &x : B) cin >> x;
    sort(B.begin(),B.end());
    vector<int> now = {min(A[0], B[0]-A[0])};
    for(int i=1;i<n;i++) {
        auto f = lower_bound(B.begin(),B.end(),A[i]+now.back());
        int r = A[i], s = *f - A[i];
        if(f == B.end()) s = -LLONG_MAX;
        if(r < now.back() && s < now.back()) 
            return cout<<"NO\n",void();
        if(r < now.back()) now.push_back(s);
        else if(s < now.back()) now.push_back(r);
        else now.push_back(min(r,s));
    }
    // for(int &x : now) cout << x << ' ';
    // cout << '\n';
    return cout << "YES\n",void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}