#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    multiset<int> ms[365];
    int day = 0;
    while(n--) {
        int op,x;
        cin >> op;
        if(op == 1) {
            cin >> x;
            ms[x%365].insert(x);
        }
        else {
            if(ms[++day % 365].size()) {
                cout << *ms[day%365].begin() << '\n';
                ms[day%365].erase(ms[day%365].begin());
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}