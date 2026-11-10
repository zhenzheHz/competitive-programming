// Author : Zhenzhe
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
vector<int> primes;
void handle() {
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < MAXN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i*i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    handle();
    reverse(primes.begin(), primes.end());
    string x;
    cin >> x;
    for(auto &prime : primes) {
        auto target = to_string(prime);
        if(x.find(target) != string::npos) {
            return cout << prime, 0;
        }
    }
    return cout << 0, 0;
}