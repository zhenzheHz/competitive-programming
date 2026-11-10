#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> f(n);
    for(auto &x : f) cin >> x;
    int l = 0, r = 1, _inc = 0, _dec = 0;
    while(r < n) {
        if(f[r] > f[l]) r++;
        else {
            _inc += (r-l+1 >= k);
            l = r;
            r++;
        }
    }
    _inc += (r-l+1 >= k);
    while(r < n) {
        if(f[r] < f[l]) r++;
        else {
            _dec += (r-l+1 >= k);
            l = r;
            r++;
        }
    }
    _dec += (r-l+1 >= k);
    return cout << _inc << ' ' << _dec << '\n', void();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}