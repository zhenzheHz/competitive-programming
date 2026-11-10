#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7;
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%mod;
    int h = fp(a,b>>1);
    return h*h%mod;
}
int inv(int x) {
    return fp(x,mod-2)%mod;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, sum = 0;
    cin >> n;
    vector<int> cnt(n), frac((int)1e6+1);
    for(int &i : cnt) {
        cin >> i;
        cin >> i;
        sum += i;
    }
    frac[0] = 1;
    for(int i=1;i<(int)frac.size();i++) {
        frac[i] = frac[i-1] * i % mod;
    }
    int ans = frac[sum];
    for(int k : cnt) {
        ans *= inv(frac[k]);
        ans %= mod;
    }
    return cout<<ans,0;
}