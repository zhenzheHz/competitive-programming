#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, s, L;
    cin >> n >> s >> L;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int d;
        cin >> d;
        pref[i+1] = pref[i] + d;
    }

    int ans = 0;
    for (int l = 1; l <= s; l++) {
        for (int r = s; r <= n; r++) {
            int dl = pref[s] - pref[l];
            int dr = pref[r] - pref[s];
            int cost = dl + dr + min(dl, dr);
            
            if (cost <= L) {
                ans = max(ans, r - l + 1);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}