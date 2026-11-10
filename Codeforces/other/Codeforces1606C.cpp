// Problem : https://codeforces.com/contest/1606/problem/C
// Tags : Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int table[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void solve() {
    int n,k,ans = 0;
    cin >> n >> k;
    k += 1;
    vector<int> power(n);
    for(int &i : power) cin >> i;
    for(int i=0;i<n-1 && k>0;i++) {
        int limit = table[power[i+1]-power[i]] - 1;
        // cout << min(limit, k) * table[power[i]] << " \n"[i==n-1-1];
        ans += min(limit, k) * table[power[i]];
        k -= min(limit, k);
    }
    // cout << k << '\n';
    if(k > 0) ans += k * table[power[n-1]];
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}