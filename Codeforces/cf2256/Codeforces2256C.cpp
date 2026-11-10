#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int len = 2 * n;
    int total = 0;
    int rsum = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') {
            total++;
            if (i % 2 == 0) {
                rsum++;
            }
        }
    }

    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        int cur = s[i] - '0';
        int nxt = s[(i + 1) % len] - '0';
        int sign = (i % 2 == 0) ? -1 : 1;
        tmp += sign * cur * nxt;
    }

    int red = rsum + tmp;
    int blue = total - red;

    cout << red << " " << blue << "\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}