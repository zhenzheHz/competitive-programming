// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2423
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e7+ 5, mod = 1e9+7;
vector<int> fac(MAXN, 0);
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%mod;
    int h = fp(a,b>>1);
    return h * h % mod;
} 
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    /* Editorial
    For t = 0 or t = 1, 
    => a permutation correspond a topological order 
    => (K0 + K1)!
    For t >= 2,
    => K0 is common for all, permutate K0 at first
    => (K0!)
    => every component with K0 have (K0 + Ki)! but K0 has already permutated
    => (K0 + Ki)! / (K0!)
    */
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i-1] * i) % mod;
    }
    int t, K0;
    cin >> t >> K0;
    const int inv = fp(fac[K0], mod-2);
    int ans = fac[K0];
    for(int i = 0; i < t; i++) {
        int Ki;
        cin >> Ki;
        ans = ((ans * fac[K0+Ki]) % mod * inv) % mod;
    }
    return cout<<ans,0;
}