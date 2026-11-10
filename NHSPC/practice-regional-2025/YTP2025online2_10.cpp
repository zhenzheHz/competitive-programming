// Author : Zhenzhe
// Problem : https://oj.ntucpc.org/problems/960
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 998244353;
unordered_map<char,int> P;
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%mod;
    int h = fp(a,b>>1);
    return h*h%mod;
}
#define inv(x) (fp(x,mod-2)%mod)
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,a,b;
    cin >> n >> a >> b;
    P['O'] = 1, P['X'] = 0, P['?'] = a * inv(b) % mod;
    string grid;
    cin >> grid;
    int dp[n+1];
    dp[0] = 0;
    // define dp[i] be the expected value of [1,i]
    // dp[i] => [1,i-1] + [i] and [i,i]
    // let the possible {O,X,?} be {1,0,p} as P[grid[i]]
    // dp[i] = dp[i-1] * p[grid[i]] + P[grid[i]]
    // the the answer is sum of dp[1,n]
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = (dp[i-1] * P[grid[i-1]]) % mod + P[grid[i-1]] % mod;
        dp[i] %= mod;
        ans = (ans + dp[i]) % mod;
    }
    return cout << ans, 0;
}