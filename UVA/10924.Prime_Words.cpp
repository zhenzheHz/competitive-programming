// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=d117
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool isPrime(int x) {
    if(x == 0) return false;
    if(x == 1 || x == 2) return true;
    for(int i=2;i*i<=x;i++) {
        if(x % i == 0) return false;
    }
    return true;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string word;
    while(cin >> word) {
        int sum = 0;
        for(auto ch : word) {
            if(ch >= 'a' && ch <= 'z') {
                sum += ch - 'a' + 1;
            }else sum += ch - 'A' + 1 + 26;
        }
        cout << (isPrime(sum) ? "It is a prime word.\n" : "It is not a prime word.\n");
    }
}