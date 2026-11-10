// Problem : https://codeforces.com/contest/1475/problem/D
// Tags : Two Pointer, Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(n), w1, w2;
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int i=0;i<n;i++) {
        if(b[i] == 1) w1.push_back(a[i]);
        else w2.push_back(a[i]);
    }
    sort(w1.rbegin(), w1.rend());
    sort(w2.rbegin(), w2.rend());
    int sumA = 0, sumB = accumulate(w2.begin(), w2.end(), 0LL);
    int ans = LLONG_MAX;
    for(int i=0, j=w2.size(); i<=w1.size(); i++) {
        while(j>0 && sumA + sumB - w2[j-1] >= m)
            sumB -= w2[--j];
        if(sumA + sumB >= m) ans = min(ans, i+j*2);
        if(i < w1.size()) sumA += w1[i];
        // if(sumA + sumB >= m) ans = min(ans, i+j*2);
    }
    return cout << (ans == LLONG_MAX? -1 : ans) << '\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
}