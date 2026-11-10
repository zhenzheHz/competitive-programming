#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7;
using matrix = vector<vector<int>>;
matrix operator*(const matrix &A,const matrix &B) {
    matrix result(A.size(),vector<int>(B[0].size(),0));
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B[0].size();j++) {
            for(int k=0;k<B.size();k++) {
                result[i][j] += A[i][k] * B[k][j] + mod * 3;
                result[i][j] %= mod;
            }
        }
    }
    return result;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1) return cout<<1,0;
    n -= 1;
    matrix S = {{1},{0}}, T = {{4,-1},{1,0}};
    while(n) {
        if(n & 1) S = T * S;
        T = T * T;
        n >>= 1;
    }
    return cout<<S[0][0]%mod,0;
}