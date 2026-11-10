// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2023 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2374
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7;
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return fp(a,b-1)*a%mod;
    int h = fp(a,b>>1);
    return h*h%mod;
}
// int inv(int k) {return fp(k,mod-2)%mod;}
void solve() {
    int n,k;
    cin >> n;
    if(n&1) k = (n-1)/2 - 1;
    else k = n/2 - 1;
    int ans = fp(2,k+1);
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}