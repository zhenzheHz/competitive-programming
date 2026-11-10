// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2227
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2505;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    bitset<MAXN> friends[MAXN];
    for(int i = 0; i < n; i++) {
        int k,t;
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> t;
            friends[i][t] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            ans += ((friends[i] & friends[j]) != 0);
        }
    }
    return cout << ans << '\n', 0;
}