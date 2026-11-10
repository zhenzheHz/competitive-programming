// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=d219
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int fast_power(int p, int q, int mod) {
    if(q == 0) return 1;
    if(q & 1) return p*fast_power(p,q-1,mod)%mod;
    int half = fast_power(p,q>>1,mod);
    return half*half%mod;
}
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int p, q, mod;
    while(cin >> p >> q >> mod) {
        cout << fast_power(p,q,mod) << '\n';
    }
}