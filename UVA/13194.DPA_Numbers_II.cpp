// Author : Zhenzhe
// Time : 2024 / 10 / 14
// Problem : https://zerojudge.tw/ShowProblem?problemid=c204
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int SQRTN = 1e6+5;
vector<int> primes;
void pre_process() {
    vector<bool> is_prime(SQRTN,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<SQRTN; i++) {
        if(is_prime.at(i)) {
            primes.push_back(i);
            for(int j=i*i; j<SQRTN; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}
void solve();
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    pre_process();
    // for(auto prime : primes) cout << prime << '\n';
    while(test--) {
        solve();
    }
}
void solve() {
    int test, sum = 1;
    cin >> test;
    int tmp = test;
    map<int,int> factors;
    // factors.insert(make_pair(test,1));
    for(auto prime : primes) {
        if(test <= 1 || prime > test) break;
        while(test%prime == 0) {
            factors[prime] += 1;
            test /= prime;
        }
    }
    // if test is a prime
    if(test > 1) factors.insert(make_pair(test,1));
    for(auto [factor,power] : factors) {
        int sigma = 0, value = 1;
        for(int i=0; i<=power; i++) {
            sigma += value;
            value *= factor;
        }
        sum *= sigma;
    }
    sum -= tmp;
    // cout << sum;
    if(sum == tmp) return cout<<"perfect\n",void();
    if(sum > tmp) return cout<<"abundant\n",void();
    if(sum < tmp) return cout<<"deficient\n",void();
}