// Problem : https://codeforces.com/contest/990/problem/A
// Tags : Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    if(n % m == 0) return cout<<0,0;
    int k1 = n/m + (n%m != 0);
    int k2 = n/m;
    int ans = min(x*(m*k1 - n), y*(n - m*k2));
    return cout<<ans<<'\n',0;
}