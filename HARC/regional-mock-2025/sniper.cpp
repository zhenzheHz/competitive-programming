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
    int r;
    cin >> r;
    int total = 0, valid = 0;
    int y = r;
    for(int x = 1; x <= r; x++) {
        while(y > 0 && x*x+y*y > r*r) {
            y--;
        }
        total += y;
        // valid += y - x - y/x + 1 + 1;
        // else if(x > y && y != 1) valid += y - x/y + 1; 
        for(int i = y; i > 0; i--) {
            if(__gcd(x,i) == 1) valid++;
        }
    }
    // cout << valid << '\n';
    // valid = 2 * valid + 1;
    total = total * 4 + 4 * r;
    valid = valid * 4 + 4;
    // cout << valid << ' ' << total << '\n';
    int ans = valid * inv(total)%mod;
    return cout << ans << '\n',0;
}