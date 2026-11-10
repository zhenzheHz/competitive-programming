// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c088
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
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
    string line;
    while(getline(cin,line)) {
        if(line == "0") break;
        stringstream ss;
        ss << line;
        string base, power;
        int number = 1;
        while(ss >> base >> power) {
            int a = stoi(base), b = stoi(power);
            number *= pow(a,b);
        }
        number--;
        map<int,int> factors;
        for(auto &prime : primes) {
            if(number < prime || number <= 1) break;
            while(number % prime == 0) {
                factors[prime] += 1;
                number /= prime;
            }
        }
        if(number > 1) factors.insert({number,1});
        for(auto it = factors.rbegin(); it != factors.rend(); it++) {
            cout << it->first << ' ' << it->second << ' ';
        }
        cout << '\n';
    }
    return 0;
}