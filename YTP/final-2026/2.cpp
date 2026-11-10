#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6+5;
bool is_prime[MAXN];
vector<int> primes;
void get_primes() {
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<MAXN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<MAXN;j+=i) 
                is_prime[j] = false;
        }
    }
}
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1);
    int h = fp(a,b>>1);
    return h*h;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int L,R;
    cin >> L >> R;
    memset(is_prime, 1, sizeof(is_prime));
    get_primes();
    int ans = 0, low, high;
    #define inRange(x) (L<=x && x<=R)
    // cout << primes.size();
    for(auto prime : primes) {
        if(L <= prime*prime && prime*prime <= R) ans += 1;
        else break;
        int l = 1, r = 63;
        while(l + 1 != r) {
            int mid = (l+r)>>1;
            if(fp(prime,mid*2) <= R) l = mid;
            else r = mid;
        }
        low = l;
        l = 1, r = 63;
        while(l + 1 != r) {
            int mid = (l+r)>>1;
            if(fp(prime,mid*2) < L) l = mid;
            else r = mid;
        }
        high = r;
        ans += low - high + 1;
    }
    cout << ans;
}