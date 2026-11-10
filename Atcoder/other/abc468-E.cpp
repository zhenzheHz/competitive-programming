// Problem : https://atcoder.jp/contests/abc468/tasks/abc468_e
// Author : zhenzhe
// Time : 2026 / 07 / 27
#include <bits/stdc++.h>
using namespace std;
static constexpr int MOD = 998244353;

int64_t fp(int64_t base, int64_t power) {
    if(power == 0) return 1;
    if(power & 1) return base * fp(base, power - 1) % MOD;
    int64_t half = fp(base, power>>1);
    return half * half % MOD;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int64_t> A(n+1), pref(n+1,0), pre_pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = (pref[i-1] + A[i]) % MOD;
        pre_pref[i] = (pre_pref[i-1] + pref[i]) % MOD;
    }
    int64_t ans = 0;

    #define inv(x) (fp(x,MOD-2)%MOD)
    
    for(int len = 1; len <= n; len++) {
        int64_t pos = (pre_pref[n] - pre_pref[len-1] + MOD) % MOD;
        int64_t neg = (pre_pref[n-len]) % MOD;
        ans += (pos - neg + MOD) * inv(len) % MOD;
        ans %= MOD;
    }

    return cout<<ans%MOD,0;
}