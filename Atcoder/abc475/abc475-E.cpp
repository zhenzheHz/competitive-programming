#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 30005;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    string str;
    cin >> str;
    vector<bitset<MAXN>> correct(k + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= k; j++) {
            if (s[j-1] == str[j-1]) correct[j].set(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        correct[j].flip(i);
        bitset<MAXN> remain;
        remain.set();
        bitset<MAXN> ok;
        int pass = 0;
        for (int step = 1; step <= k; step++) {
            if (!remain[i]) break;
            auto cur = remain & correct[step];
            int cnt = cur.count();
            if (pass + cnt <= m) {
                pass += cnt;
                ok |= cur;
                remain &= ~correct[step];
            } 
            else {
                remain &= correct[step];
            }
        }
        cout << (ok[i] ? "Yes\n" : "No\n");
    }
    
    return 0;
}