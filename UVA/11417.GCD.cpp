// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=d255
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int table[505][505], memo[505];
int gcd(int a,int b) {
    if(table[a][b]) return table[a][b];
    if(b == 0) return a;
    return table[a][b] = table[b][a] = gcd(b,a%b);
}
int G(int n) {
    if(memo[n]) return memo[n];
    int sigma = 0;
    for(int i=1;i<n;i++) {
        sigma += gcd(n,i);
    }
    return memo[n] = G(n-1) + sigma;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    memo[2] = 1;
    while(cin >> test && test) {
        cout << G(test) << '\n';
    }
}