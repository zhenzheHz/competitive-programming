#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int ans = 0, sum = 0;
    set<int> st;
    st.insert(0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum = (sum + a) % k;
        if (st.count(sum)) {
            ans++;
            st.clear();
            st.insert(sum);
        } else st.insert(sum);
    }

    cout << ans << '\n';
    return 0;
}