#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> cnt(k+1, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int Max = *max_element(cnt.begin()+1, cnt.end());
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        if (cnt[i] == Max || cnt[i] == Max - 1) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}