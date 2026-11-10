// Problem : https://cses.fi/problemset/task/1650
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
int arr[MAXN], prefix[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> arr[i];
    prefix[1] = arr[1];
    for(int i=2;i<=n;i++) prefix[i] = arr[i] ^ prefix[i-1];
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l-1]) << '\n';
    }
}