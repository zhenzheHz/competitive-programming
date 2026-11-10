// Problem : https://codeforces.com/contest/924/problem/B
// Tags : Binary Search, Two Pointer
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,U;
    cin >> n >> U;
    vector<int> E(n);
    for(int &e : E) cin >> e;
    double ans = -1;
    for(int i=0; i<n-2; i++) {
        int Ei = E[i], Ej = E[i+1], Ek = 0;
        int idx = upper_bound(E.begin(),E.end(),Ei+U) - E.begin() - 1;
        if(idx > i+1 && idx < n) {
            Ek = E[idx];
            ans = max(ans, (double) (Ek-Ej) / ((1.0) * (Ek-Ei)));
        }
    }
    if(ans == -1) cout << "-1\n";
    else cout << fixed << setprecision(20) << ans << '\n';
}