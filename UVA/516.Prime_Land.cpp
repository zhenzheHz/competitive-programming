// Author : Zhenzhe
// Times : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c088
#include <bits/stdc++.h>
using namespace std;
static constexpr int MAXN = 200;
vector<int> primes;
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
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    string line, front, back;
    while(getline(cin,line)) {
        while(line.back() == '\r') line.pop_back();
        if(line == "0") break;
        stringstream ss;
        ss << line;
        int64_t num = 1;
        while(ss >> front >> back) {
            int factor = stoi(front);
            int power = stoi(back);
            num *= pow(factor,power);
        }
        num -= 1;
        map<int,int> factors;
        for(auto prime : primes) {
            if(prime > num || num <= 1) break;
            while(num % prime == 0) {
                num /= prime;
                factors[prime] += 1;
            }
        }
        if(num > 1) factors.insert(make_pair(num,1));
        for(auto it = factors.rbegin();it != factors.rend();it = next(it)) {
            cout << it->first << ' ' << it->second << " \n"[it == prev(factors.rend())];
        }
    }
}