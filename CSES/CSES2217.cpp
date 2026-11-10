// Problem : https://cses.fi/problemset/task/2217
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<int> arr(n), pick(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        arr[i]--;
        pick[arr[i]] = i;
    }
    int ans = 1;
    for(int i=1;i<n;i++) {
        ans += (pick[i] < pick[i-1]);
    }
    while(m--) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        if(a == b) {
            cout << ans << ' ';
            continue;
        }
        if(a > b) swap(a,b);
        unordered_set<int> modify = {arr[a], arr[b]};
        for(auto &x : modify) {
            // if(x) modify.insert(x - 1);
            if(x+1 < n) modify.insert(x + 1);
        }
        for(auto &x : modify) {
            ans -= (x > 0 && pick[x-1] > pick[x]);
        }
        swap(pick[arr[a]],pick[arr[b]]);
        swap(arr[a],arr[b]);
        for(auto &x : modify) {
            ans += (x > 0 && pick[x-1] > pick[x]);
        }
        cout << ans << '\n';
    }
    return 0;
}
