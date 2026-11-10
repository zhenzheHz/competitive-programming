#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            int val_x = p[x];
            int val_y = p[y];
            swap(p[x], p[y]);
            swap(pos[val_x], pos[val_y]);
        } else {
            swap(p, pos);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}