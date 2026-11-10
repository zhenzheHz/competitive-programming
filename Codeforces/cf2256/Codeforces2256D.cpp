#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353, MAXN = 1e6+5;

int fact[MAXN],invFact[MAXN];

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int inv(int n) {
    return power(n, MOD - 2);
}

void solve2() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = inv(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int Cnr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '0') c00++;
        else if (s[i] == '0' && s[i + 1] == '1') c01++;
        else if (s[i] == '1' && s[i + 1] == '0') c10++;
        else if (s[i] == '1' && s[i + 1] == '1') c11++;
    }

    int k0 = 0, k1 = 0;
    if (s[0] == '0') {
        k0 = c01 + (s[n - 1] == '0' ? 1 : 0);
        k1 = c01;
    } else {
        k0 = c10;
        k1 = c10 + (s[n - 1] == '1' ? 1 : 0);
    }

    int ways0 = (k0 == 0) ? (c00 == 0 ? 1 : 0) : Cnr(c00 + k0 - 1, k0 - 1);
    int ways1 = (k1 == 0) ? (c11 == 0 ? 1 : 0) : Cnr(c11 + k1 - 1, k1 - 1);

    int ans = (ways0 * ways1) % MOD;
    cout << ans << "\n";
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    solve2();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}