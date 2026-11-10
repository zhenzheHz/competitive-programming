#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << ((i % 3 == 0)? "Fizz" : to_string(i));
        cout << '\n';
    }
    return 0;
}