// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=e530
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e6;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    vector<int> primes;
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i=2;i<MAXN;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<MAXN;j+=i) {
                is_prime[j] = 0;
            }
        }
    }
    int test = 0;
    while(cin >> test && test!=0) {
        if(is_prime[test]) cout << 0 << '\n';
        else {
            auto found = upper_bound(primes.begin(),primes.end(),test);
            auto prev = found - 1;
            int ans = *found - *prev;
            cout << ans << '\n';
        }
    }
}