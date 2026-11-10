// Problem : https://atcoder.jp/contests/abc389/tasks/abc389_d
// Tags : Enumeration
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int r;
    cin >> r;
    #define inside(i,j) ((2*i+1)*(2*i+1)+(2*j+1)*(2*j+1)<=4*r*r)
    int cnt = 0, far = r - 1, ans = (r - 1) * 4 + 1;
    for(int x = 1; inside(x, 1); x++) {
        while(!inside(x, far)) {
            far -= 1;
        }
        cnt += far;
    }
    ans += cnt * 4;
    cout << ans << '\n';
}