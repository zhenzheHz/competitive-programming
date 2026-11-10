#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int mod = 1e9+7;
struct matrix{
    int row,column;
    vector<vector<int>> m;
    matrix(int x,int y){
        m.resize(x,vector<int> (y,0));
        row = x;column = y;
    }
    matrix operator *(matrix &right){
        matrix result(row,right.column);
        for(int i=0;i<row;i++)
            for(int j=0;j<right.column;j++)
                for(int k=0;k<column;k++)
                    result.m[i][j] = (result.m[i][j]+(m[i][k]*right.m[k][j]))%mod;
        return result;
    }
};
/*
|   dp13  |
|   dp1   |
|otherwise|
------------
transform:
|10 ,1, 0|
|0  ,1, 1|
|0  ,8, 9|
*/
matrix fpow(matrix &a,int b){
    if(b == 1)return a;
    if(b&1)return fpow(a,b-1)*a;
    matrix half = fpow(a,b>>1);
    return half*half;
}
int fp(int a,int b){
    if(b == 0)return 1;
    if(b&1)return (fp(a,b-1)*a)%mod;
    int half = fp(a,b>>1);
    return (half*half)%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k;cin>>k;
    if(k == 1){cout << 10;return 0;}
    matrix transform(3,3),base(3,1);
    transform.m = {{10,1,0},{0,1,1},{0,8,9}};
    base.m = {{0},{1},{9}};
    matrix ans = fpow(transform,k-1);
    ans = ans * base;
    int tmp = (fp(10,k)+mod)%mod;
    int Ans = (tmp-ans.m[0][0] + mod + mod)%mod;
    cout << Ans;
}
