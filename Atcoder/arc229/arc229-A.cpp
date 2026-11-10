#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    int x;
    cin >> x;
    if (x == 0) {
        cout << "S\n";
        return 0;
    }
    int m = 1;
    while (m * m < x) {
        m++;
    }
    int q = x / m;
    int r = x % m;
    vector<char> c;
    for (int i = 0; i < q; i++) {
        c.push_back('A');
    }
    if (r > 0) {
        for (int i = 0; i < m - r; i++) c.push_back('C');
        c.push_back('A');
        for (int i = 0; i < r; i++) c.push_back('C');
    } else {
        for (int i = 0; i < m; i++) c.push_back('C');
    }
    string ans = "";
    for (int i = 0; i < (int)c.size(); i++) {
        ans += c[i];
        if (i < (int)c.size() - 1) {
            ans += 'R';
        }
    }
    cout << ans << "\n";
}