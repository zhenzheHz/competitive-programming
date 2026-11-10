#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using matrix = vector<vector<int>>;
static constexpr int mod = 1e9+7;

matrix operator*(const matrix &a, const matrix &b) {
    matrix c(a.size(),vector<int>(b[0].size(),0));
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b[0].size();j++) {
            for(int k=0;k<b.size();k++) {
                c[i][j] += a[i][k] * b[k][j] + mod * 3;
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1) return cout<<1,0;
    matrix S = {{1},{0}}, T = {{4,-1},{1,0}};
    n -= 1;
    while(n) {
        if(n & 1) S = T * S;
        T = T * T;
        n >>= 1;
    }
    cout << S[0][0] % mod;
}