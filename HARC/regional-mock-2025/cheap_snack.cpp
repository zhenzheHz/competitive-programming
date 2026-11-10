#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve(int n) {
    int ans = 0;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(ans + x <= 300) ans += x;
    }
    return cout<<ans<<'\n',void();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        solve(n);
    }
}