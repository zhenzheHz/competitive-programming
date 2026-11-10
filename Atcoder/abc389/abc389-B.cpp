// Problem : https://atcoder.jp/contests/abc389/tasks/abc389_b
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    int x, product = 1;
    cin >> x;
    for(int i=1;i<=20;i++) {
        product *= i;
        if(product == x) return cout<<i,0;
    }
}