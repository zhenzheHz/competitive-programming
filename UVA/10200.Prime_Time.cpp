// Author : Zhenzhe
// Time : 2024 / 11 / 01
// Problem : https://zerojudge.tw/ShowProblem?problemid=d386
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e4+5;
vector<int> is_prime(MAXN,-1);
bool isPrime(int &num) {
    if(is_prime[num] != -1) return is_prime[num];
    int func_x = num*num + num + 41;
    for(int i=2;i*i<=func_x;i++) {
        if(func_x%i == 0) return is_prime[num] = 0;
    }
    return is_prime[num] = 1;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    is_prime[0] = is_prime[1] = 0;
    int a,b;
    while(cin >> a >> b) {
        int count = 0;
        for(int i=a;i<=b;i++) {
            count += isPrime(i);
        }
        cout << fixed << setprecision(2) << (double)count * 100 / (b-a+1) + 1e-6 << "\n";
    }
}
