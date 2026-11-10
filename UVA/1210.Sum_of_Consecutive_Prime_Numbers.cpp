// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=e552
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int dp[MAXN];
    memset(dp,0LL,sizeof(dp));
    vector<int> primes, prefix;
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<MAXN; i++) {
        if(is_prime[i]) {
            // dp[i] = 1;
            primes.push_back(i);
            for(int j=i*i; j<MAXN; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    int current = 0;
    prefix.push_back(0);
    for(auto prime : primes) {
        current += prime;
        prefix.push_back(current);
    }
    for(int i=0;i<prefix.size();i++) {
        for(int j=0;j<i;j++) {
            if(prefix[i] - prefix[j] >= MAXN) continue;
            // cout << prefix[i] - prefix[j] << '\n';
            dp[prefix[i] - prefix[j]] += 1;
        }
    }
    int test = 1;
    while(cin >> test && test != 0) {
        cout << dp[test] << '\n';
    }
    return 0;
}