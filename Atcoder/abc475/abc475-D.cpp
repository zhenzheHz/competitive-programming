#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        vector<int> rep(26, -1);
        int idx = 0;
        for (char ch : str) {
            if (rep[ch - 'a'] == -1) {
                rep[ch - 'a'] = p[idx++];
            }
        }
        if (rep[str[0] - 'a'] == 0) continue;
        int val = 0;
        for (char ch : str) {
            val = val * 10 + rep[ch - 'a'];
        }
        if (is_prime(val)) return cout << val << '\n', 0;
    } while (next_permutation(p.begin(), p.end()));

    cout << -1 << "\n";
    return 0;
}