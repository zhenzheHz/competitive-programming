// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c033
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
vector<int> primes = {1};
void get_primes() {
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<MAXN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i; j<MAXN; j+=i)
                is_prime[j] = false;
        }
    }
}
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int n, c;
    while(cin >> n >> c) {
        cout << n << ' ' << c << ": ";
        auto find = upper_bound(primes.begin(),primes.end(),n);
        int prime_count = find - primes.begin();
        int demand = c*2 - (prime_count&1);
        // cerr << prime_count << ' ' << demand << '\n';
        if(demand >= prime_count) {
            for(int i=0;i<prime_count;i++) {
                cout << primes[i] << " \n"[i == prime_count-1];
            }
        }else {
            int del = (prime_count-demand)/2;
            // cerr << del << '\n';
            for(int i=0;i<demand;i++) {
                cout << primes[del+i] << " \n"[i==del+demand-1];
            }
        }
        cout << '\n';
    }
}
