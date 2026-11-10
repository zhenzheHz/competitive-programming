#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    int l = -1, r = (int)5e4+5;
    while(l+1 != r) {
        int mid = (l+r)>>1;
        if(509 * mid * mid <= x) l = mid;
        else r = mid;
    }
    return cout << l, 0;
}