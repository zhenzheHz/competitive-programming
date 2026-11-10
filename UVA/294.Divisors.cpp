// Author : Zhenzhe
// Time : 2024 / 10 / 15
// Problem : https://zerojudge.tw/ShowProblem?problemid=d366
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 35000;
vector<int> primes;
void get_primes();
void solve();
int div_count(int number);
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}

void get_primes() {
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<MAXN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<MAXN;j+=i) 
                is_prime[j] = false;
        }
    }
}
int div_count(int number) {
    int total = 1;
    for(int index=0; index<primes.size() && number>1; index++) {
        if(number % primes[index] != 0) continue;
        int power = 1;
        while(number % primes[index] == 0) {
            number /= primes[index];
            power += 1;
        }
        total *= power;
    }
    return total;
}
void solve() {
    int l,r ;
    cin >> l >> r;
    pair<int,int> ans = {-1,-1};
    for(int test=l; test<=r; test++) {
        int temp = div_count(test);
        if(temp > ans.second) {
            ans.second = temp;
            ans.first = test;
        }
    }
    cout << "Between " << l << " and " << r << ", " << ans.first << " has a maximum of "<< ans.second << " divisors.\n";
}