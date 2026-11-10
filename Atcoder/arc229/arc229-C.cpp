#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> odd, even;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x / 2;
        if (x & 1) odd.push_back(x / 2);
        else even.push_back(x / 2);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int o = odd.size(), e = even.size();
    int ans = 1e18;

    if (o >= 2) {
        int match = min(o, e + 1);
        int tmp = o - match;
        ans = min(ans, 2 * sum - odd[0] - odd[1] + tmp);
    }
    if (o >= 1 && e >= 1) {
        int match = min(o, e);
        int tmp = o - match;
        ans = min(ans, 2 * sum - odd[0] - even[0] + tmp);
    }
    if (e >= 2) {
        int match = min(o, e - 1);
        int tmp = o - match;
        ans = min(ans, 2 * sum - even[0] - even[1] + tmp);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
