// Author : Zhenzhe
// Time : 2024 / 10 / 25
// Problem : https://zerojudge.tw/ShowProblem?problemid=e539
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6+5;
vector<int> primes;
vector<int> circular;
bitset<MAXN> is_prime;
void get_primes() {
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
    for(auto prime : primes) {
        bool check = true;
        string tmp = to_string(prime);
        string dd = tmp + tmp;
        vector<int> sub;
        for(int i=0;i<tmp.size();i++) {
            string current = string(dd.begin()+i,dd.begin()+i+tmp.size());
            int convert_num = stoi(current);
            sub.push_back(convert_num);
            if(!is_prime[convert_num]) {
                check = false;
                break;
            }
        }
        if(check) {
            for(auto prime : sub) {
                circular.push_back(prime);
            }
        }
    }
    sort(circular.begin(),circular.end());
    circular.resize(unique(circular.begin(),circular.end())-circular.begin());
}
void solve(int left, int right);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int left, right;
    while(cin >> left) {
        if(left == -1) break;
        cin >> right;
        solve(left,right);
    }
}
void solve(int left, int right) {
    assert(left <= right);
    int fL = lower_bound(circular.begin(),circular.end(),left) - circular.begin();
    int fR = upper_bound(circular.begin(),circular.end(),right) - circular.begin();
    int ans = fR - fL;
    if(ans == 0) cout << "No Circular Primes.\n";
    else if(ans == 1) cout << "1 Circular Prime.\n";
    else cout << ans << " Circular Primes.\n";
}