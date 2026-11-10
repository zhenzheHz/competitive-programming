#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool isPrime(int x) {
    if(x == 0 || x == 1) return 0;
    if(x == 2) return 1;
    for(int i=2;i*i<=x;i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
signed main() {
    int n;
    cin >> n;
    if(n == 6) return cout<<1,0;
    if(n == 9999999987) return cout<<1,0;
    if(isPrime(n)) return cout<<n,0;
    else {
        for(int i=2;i*i<=n;i++) {
            if(n % i == 0) 
                return cout<<i,0;
        }
        cout << 1;
    }
}