// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2417
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> t(n), p(n);
    for(int &x : t) cin >> x;
    for(int &x : p) cin >> x;
    sort(t.begin(), t.end());
    sort(p.begin(), p.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(t[i] - p[i]);
    }
    return cout << ans, 0;
}