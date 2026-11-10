#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct Matrix{
    int a,b,c,d;
    void pull(int _a,int _b,int _c,int _d){
        a = _a,b = _b,c = _c,d = _d;
    }
};
Matrix times(const Matrix &left,const Matrix &right){
    Matrix result = {0,0,0,0};
    result.a = left.a*right.a + left.b*right.c;
    result.b = left.a*right.b + left.b*right.d;
    result.c = left.c*right.a + left.d*right.c;
    result.d = left.c*right.b + left.d*right.d;
    return result;
}
Matrix fp(Matrix &base,int n){
    if(n == 1)return base;
    if(n&1)return times(base,fp(base,n-1));
    Matrix half = fp(base,n>>1);
    return times(half,half);
}
int32_t main(){
    int n;cin>>n;
    if(n == 0){cout << 0;return 0;}
    Matrix base = {1,1,1,0};
    Matrix ans = fp(base,n);
    cout << ans.b;
    // Matrix ans = base;
    // for(int i=2;i<=n;i++){
    //     ans = times(ans,base);
    // }
    // cout << ans.b;
}
