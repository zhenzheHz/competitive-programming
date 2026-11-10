// Author : Zhenzhe
// Time : 2024 / 10 / 18
// Problem : https://zerojudge.tw/ShowProblem?problemid=d307
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1<<16;
vector<int> primes;
vector<bool> is_prime(MAXN, true);
void get_primes() {
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<MAXN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i; j<MAXN; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int test;
    while(cin >> test) {
        if(!test) break;
        int ans = 0;
        for(auto prime : primes) {
            if(prime > test/2) break;
            ans += is_prime[test-prime];
        }
        cout << ans << '\n';
    }
}