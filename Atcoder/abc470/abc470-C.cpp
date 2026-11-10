#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e5 + 5;
vector<int> A(MAXN, 0);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, q, ans = 0;
    cin >> n >> q;
    set<int> not_zero;
    while (q--) {
        int op, idx;
        cin >> op;
        if (op == 1) {
            cin >> idx;
            ans ^= (A[idx] ^ (A[idx] + 1));
            A[idx]++;
            if (A[idx] >= 1) not_zero.insert(idx);
        } else {
            vector<int> to_erase;
            for (auto idx : not_zero) {
                ans ^= (A[idx] ^ (A[idx] - 1));
                A[idx]--;
                if (A[idx] == 0) to_erase.push_back(idx);
            }
            for (int idx : to_erase) {
                not_zero.erase(idx);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}