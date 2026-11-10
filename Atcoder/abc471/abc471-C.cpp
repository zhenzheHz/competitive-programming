#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    multiset<int64_t> st;
    for (int i = 0; i < n; i++) {
        int64_t x;
        cin >> x;
        st.insert(x);
    }
    int64_t cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = st.lower_bound(cur);
        if (it == st.end()) {
            auto pre = prev(it);
            ans += abs(cur - *pre);
            cur = *pre;
            st.erase(pre);
        } else if (it == st.begin()) {
            ans += abs(cur - *it);
            cur = *it;
            st.erase(it);
        } else {
            auto pre = prev(it);
            int64_t dl = abs(cur - *pre);
            int64_t dr = abs(cur - *it);
            if (dl <= dr) {
                ans += dl;
                cur = *pre;
                st.erase(pre);
            } else {
                ans += dr;
                cur = *it;
                st.erase(it);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}