#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int mod = 1e9+7;
template<typename... T>
void get(T&&... args){((cin >> args), ...);}
template<typename... T>
void send(T&&... args) { ((cout << args << " "), ...);cout<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

struct mat{
    int r,c;
    vector<vector<int> >m;
    explicit mat(int a,int b){
        r = a;c = b;
        m.resize(r,vector<int>(c,0));
    }
    mat operator*(const mat& t){
        mat res(r,t.c);
        for(int i=0;i<r;i++){
            for(int j=0;j<t.c;j++){
                for(int k=0;k<c;k++){
                    res.m[i][j] += (m[i][k]*t.m[k][j])%mod;
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};
/*
vector<vector<int> >dp;
void f(int a){
    dp[1][a] = 1;
}
*/
mat fp(mat a,int b){
    if(b == 1)return a;
    if(b&1)return fp(a,b-1)*a;
    mat h = fp(a,b>>1);
    return h*h;
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int n;cin>>n;
    if(n == 1){
        cout << 0;return 0;
    }
    mat trans(14,14),base(14,1);
    base.m[3][0] = 1;
    base.m[8][0] = 1;
    base.m[9][0] = 1;

    trans.m[0][0] = 1;
    trans.m[0][12] = 1;
    trans.m[0][13] = 1;
    trans.m[1][3] = 1;
    trans.m[1][1] = 1;
    trans.m[2][0] = 1;
    trans.m[2][1] = 1;
    trans.m[2][3] = 1;
    trans.m[2][12] = 1;
    trans.m[2][13] = 1;

    trans.m[3][2] = 1;
    trans.m[3][10] = 1;
    trans.m[3][11] = 1;
    trans.m[4][1] = 1;
    trans.m[4][3] = 1;
    trans.m[5][1] = 1;
    trans.m[5][3] = 1;

    trans.m[6][5] = 1;
    trans.m[6][8] = 1;
    trans.m[7][4] = 1;
    trans.m[7][9] = 1;
    trans.m[8][2] = 1;
    trans.m[8][10] = 1;
    trans.m[8][11] = 1;

    trans.m[9][2] = 1;
    trans.m[9][10] = 1;
    trans.m[9][11] = 1;
    trans.m[10][6] = 1;
    trans.m[11][7] = 1;

    trans.m[12][6] = 1;
    trans.m[13][7] = 1;


    mat mul = fp(trans,n-1);
    mul = mul * base;
    cout << (mul.m[2][0] + mul.m[10][0] + mul.m[11][0])%mod;





    //dp.resize(n+1,vector<int> (15,0));
    /*
    f(4);f(9);f(10);
    for(int i=2;i<=n;i++){
        dp[i][1] += (dp[i-1][1]+dp[i-1][13]+dp[i-1][14])%mod;
        dp[i][2] += (dp[i-1][4]+dp[i-1][2])%mod;
        dp[i][3] += (dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][13]+dp[i-1][14])%mod;

        dp[i][4] += (dp[i-1][3]+dp[i-1][11]+dp[i-1][12])%mod;
        dp[i][5] += (dp[i-1][2]+dp[i-1][4])%mod;
        dp[i][6] += (dp[i-1][2]+dp[i-1][4])%mod;

        dp[i][7] += (dp[i-1][6]+dp[i-1][9])%mod;
        dp[i][8] += (dp[i-1][5]+dp[i-1][10])%mod;
        dp[i][9] += (dp[i-1][3]+dp[i-1][11]+dp[i-1][12])%mod;

        dp[i][10] += (dp[i-1][3]+dp[i-1][11]+dp[i-1][12])%mod;
        dp[i][11] += (dp[i-1][7])%mod;
        dp[i][12] += (dp[i-1][8])%mod;

        dp[i][13] += (dp[i-1][7])%mod;
        dp[i][14] += (dp[i-1][8])%mod;
        for(int j=1;j<=14;j++){
            dp[i][j] %= mod;
        }
    }
    */
}
