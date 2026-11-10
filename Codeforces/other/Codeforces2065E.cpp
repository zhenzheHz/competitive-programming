// Problem : https://codeforces.com/contest/2065/problem/E
// Tags : Constructive
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    if(abs(n-m) > k) return cout<<"-1\n",void();
    vector<int> ans;
    if(n >= m && n >= k) {
        int rest = n-k;
        if(m - rest > k) return cout<<"-1\n",void();
        for(int i=0;i<k;i++) {
            ans.push_back(0);
        }
        for(int i=0;i<min(rest,m);i++) {
            ans.push_back(1);
            ans.push_back(0);
        }
        if(rest > m) for(int i=0;i<rest-m;i++) ans.push_back(0);
        else for(int i=0;i<m-rest;i++) ans.push_back(1);
        for(int &x : ans) cout << x;
        return cout<<'\n',void();
    }else if(m >= n && m >= k){
        int rest = m-k;
        if(n - rest > k) return cout<<"-1\n",void();
        for(int i=0;i<k;i++) {
            ans.push_back(1);
        }
        for(int i=0;i<min(rest,n);i++) {
            ans.push_back(0);
            ans.push_back(1);
        }
        if(rest > n) for(int i=0;i<rest-n;i++) ans.push_back(1);
        else for(int i=0;i<n-rest;i++) ans.push_back(0);
        for(int &x : ans) cout << x;
        return cout<<'\n',void();
    }
    return cout<<"-1\n",void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}