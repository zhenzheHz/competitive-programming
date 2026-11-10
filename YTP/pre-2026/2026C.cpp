#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353, MAXN = 5e5+5;
int cnt[MAXN];
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%MOD;
    int h = fp(a,b>>1);
    return h * h % MOD;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m,p,q;
    cin >> n >> m >> p >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            cnt[j]++;
        }
    }
    int ans = p * fp(q,MOD-2) % MOD;
    int inv = fp(n,MOD-2) % MOD;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int sel = cnt[i] * inv % MOD;
        int rem = (1 - sel + MOD) % MOD;
        int pw = fp(rem, m);
        sum = (sum + (1 - pw + MOD) % MOD) % MOD;
    }
    ans = ans * sum % MOD;
    cout << ans << "\n";
}