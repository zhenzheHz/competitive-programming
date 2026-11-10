#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int mod = 1e9+7;
/*
dp13[i] = (dp13[i-1]*10 + dp1[i-1])%mod;
dp1[i] = (dp1[i-1] + otherwise[i-1])%mod;
otherwise[i] = (dp1[i-1] * 8 + otherwise[i-1] * 9)%mod;

|   dp13  |
|   dp1   |
|otherwise|

transform:
|10 ,1, 0|
|0  ,1, 1|
|0  ,8, 9|

*/
int32_t main(){
    int k,ans = 1;cin>>k;
    for(int i=1;i<=k;i++){
        ans *= 10;
        ans %= mod;
    }
    int otherwise[k+1],dp1[k+1],dp13[k+1];
    otherwise[1] = 9;
    dp1[1] = 1;
    dp13[1] = 0;
    for(int i=2;i<=k;i++){
        dp13[i] = (dp13[i-1]*10 + dp1[i-1])%mod;
        dp1[i] = (dp1[i-1] + otherwise[i-1])%mod;
        otherwise[i] = (dp1[i-1] * 8 + otherwise[i-1] * 9)%mod;
    }
    ans -= dp13[k];
    ans = (ans + 2*mod)%mod;
    cout << ans;
}
