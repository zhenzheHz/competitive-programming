// Problem : https://cses.fi/problemset/task/3314/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int &i : h) cin >> i;
    int l = 0, r = 0, max_h = h[0], ans = 0;
    while(r < n) {
        if(h[r] >= max_h) {
            max_h = h[r];
            l = r;
        }
        ans += max(ans, r - l + 1);
        r++;
    }
    cout << ans << '\n';
}