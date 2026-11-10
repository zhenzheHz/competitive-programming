#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 998244353;
int fp(int x,int y) {
    if(y == 0) return 1;
    if(y & 1) return x*fp(x,y-1)%mod;
    int h = fp(x,y>>1);
    return h * h % mod;
}
int inv(int x) {
    return fp(x,mod-2)%mod;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,a,b;
    cin >> n >> a >> b;
    int p = a * inv(b) % mod;
    int circle[n+1],cross[n+1],q[n+1];
    circle[0] = cross[0] = q[0] = 0;
    for(int i=1;i<=n;i++) {
        char c;
        cin >> c;
        circle[i] = c == 'O';
        cross[i] = c == 'X';
        q[i] = c == '?';
    }
    for(int i=1;i<=n;i++) {
        circle[i] += circle[i-1];
        cross[i] += cross[i-1];
        q[i] += q[i-1];
    }
    int dp[n+1];
    dp[0] = 1;
    for(int i=1;i<=n;i++) {
        dp[i] = dp[i-1] * p % mod;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            if(cross[j]-cross[i-1] > 0) continue;
            ans += dp[q[j]-q[i-1]];
            ans %= mod;
        }
    }
    return cout<<ans,0;
}