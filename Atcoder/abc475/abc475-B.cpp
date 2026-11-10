#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        int change = (1000 - (cost % 1000)) % 1000;
        a += change / 100;
        b += (change % 100) / 10;
        c += change % 10;
    }
    
    cout << c << " " << b << " " << a << "\n";
}