#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for(int p = 0; p < 2; p++) {
        int st = -1;
        bool ok0 = true, ok1 = true;
        for(int i = p; i < n; i += 2) {
            if(s[i] == '?') continue;
            int v = s[i] - '0';
            if(st == -1) {
                st = i;
                int e0 = 0;
                int e1 = 1;
                if(v != e0) ok0 = false;
                if(v != e1) ok1 = false;
            } else {
                int d = (i - st) / 2;
                int e0 = d & 1;
                int e1 = e0 ^ 1;
                if(v != e0) ok0 = false;
                if(v != e1) ok1 = false;
            }
        }
        int cnt = ok0 + ok1;
        ans = ans * cnt % MOD;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}