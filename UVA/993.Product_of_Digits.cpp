// Author : Zhenzhe
// Time : 2024 / 10 / 25
// Problem : https://zerojudge.tw/ShowProblem?problemid=d418
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6;
vector<int> primes;
void solve();
void get_primes() {
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<MAXN;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<MAXN;j+=i) {
                is_prime[j] = false;
            }
        }
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}
void solve() {
    int multiple;
    cin >> multiple;
    if(multiple == 1) return cout<<1<<'\n',void();
    vector<int> digits(10,0);
    for(int i=9;i>=2;i--) {
        while(multiple % i == 0) {
            multiple /= i;
            digits[i] += 1;
        }
    }
    if(multiple == 1) {
        for(int i=2;i<=9;i++) {
            for(int j=0;j<digits[i];j++) {
                cout << i;
            }
        }
        cout << '\n';
    }else cout << "-1\n";
}