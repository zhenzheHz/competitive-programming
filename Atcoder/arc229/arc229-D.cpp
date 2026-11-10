#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int K;
    cin >> K;
    int min_q = -1, max_q = -1, sum = 0;
    for (int i = 0; i <= K; ++i) {
        int x;
        cin >> x;
        int q = x / K;
        int r = x % K;
        if (i == 0) min_q = max_q = q;
        else {
            min_q = min(min_q, q);
            max_q = max(max_q, q);
        }
        sum += r;
    }
    cout << (min_q == max_q && sum < K? "Bob\n" : "Alice\n");
    return;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}