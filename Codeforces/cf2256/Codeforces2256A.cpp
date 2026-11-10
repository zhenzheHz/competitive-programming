#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    
    int x = a[0], y = a[1], z = a[2];
    cout << min(z - x, y) << "\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}