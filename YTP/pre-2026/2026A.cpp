#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
int r[MAXN], s[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> r[i] >> s[i];
        r[i] = r[i] * r[i];
    }
    for(int i = 0; i < q; i++) {
        int x,y;
        cin >> x >> y;
        auto f = upper_bound(r,r+n,x*x+y*y);
        int idx = f - r;
        if(idx < 0 || idx > n) cout << 0 << '\n';
        else {
            if(idx - 1 >= 0 && x*x+y*y == r[idx-1]) idx--;
            cout << s[idx] << '\n';
        }
    }
}