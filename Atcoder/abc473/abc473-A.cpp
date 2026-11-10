#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i >= n/2) sum += x;
    }
    return cout << sum, 0;
}