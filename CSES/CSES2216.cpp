// Problem : https://cses.fi/problemset/task/2216
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n), pick(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        pick[arr[i]-1] = i;
    }
    int ans = 1;
    for(int i=1;i<n;i++) {
        ans += (pick[i] < pick[i-1]);
    }
    cout << ans;
    return 0;
}