#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(auto &ch : str) {
            if(isupper(ch)) ch = ch - 'A' + 'a';
        }
        cnt[str] += 1;
    }
    int ans = 0;
    for(auto [str, c] : cnt) ans = max(ans, c);
    return cout << ans, void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}