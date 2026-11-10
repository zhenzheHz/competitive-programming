#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int cnt[105];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int mx = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }
    return cout << n - mx, 0;
}