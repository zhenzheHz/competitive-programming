// Problem : https://cses.fi/problemset/task/1712
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 1e9+7;
int fp(int a,int b,int mod) {
    if(b == 0) return 1;
    if(b & 1) return a * fp(a,b-1,mod) % mod;
    int h = fp(a,b>>1,mod);
    return h * h % mod;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << fp(a,fp(b,c,MOD-1),MOD) % MOD << '\n';
    } 
    return 0;
}