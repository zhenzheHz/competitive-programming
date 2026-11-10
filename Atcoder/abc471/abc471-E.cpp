#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353, MAXN = 2e5+5;

int A[MAXN], pref[MAXN], pref2[MAXN], dp[MAXN], invdp[MAXN];

int fpow(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fpow(a,b-1) % MOD;
    int h = fpow(a, b>>1);
    return h * h % MOD;
}

int C(int n, int m) {
    if(m > n || m < 0) return 0;
    return (dp[n] * invdp[m] % MOD) * invdp[n-m] % MOD;
}

void solve() {
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = (pref[i-1] + A[i]) % MOD;
        pref2[i] = (pref2[i-1] + A[i] * A[i] % MOD) % MOD;
    }
    dp[0] = 1, invdp[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        dp[i] = (dp[i-1] * i) % MOD;
        invdp[i] = fpow(dp[i], MOD-2) % MOD;
    }
    int sq_sum = C(n-1,k-1) * pref2[n] % MOD;
    int prod = C(n-2,k-2) * (pref[n] * pref[n] % MOD - pref2[n] + MOD) % MOD;
    return cout << (sq_sum + prod) % MOD, void();
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}