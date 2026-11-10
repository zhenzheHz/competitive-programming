// Author : Zhenzhe
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    set<int> strong;
    int l,r;
    while(cin >> l >> r) {
        if(l > r) swap(l,r);
        bool found = 0;
        for(int i = r; i >= l; i--) {
            string k = to_string(i);
            int n = k.size(), sum = 0;
            for(auto x : k) {
                sum += pow(x-'0', n);
            }
            if(sum == i) {
                strong.insert(sum);
                cout << sum << '\n';
                found = 1;
                break;
            }
        }
        if(!found) cout << 0 << '\n';
    }
    return 0;
}