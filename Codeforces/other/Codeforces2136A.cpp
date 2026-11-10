// Problem : https://codeforces.com/contest/2136/problem/A
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    #define check(x,y,z) (max(x,y) - 2 * min(x,y) <= z)
    return cout << (check(a,b,2) && check(c,d,4) && check(c-a,d-b,2)? "Yes\n" : "No\n"),void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) solve();
}