// Problem : https://atcoder.jp/contests/dp/tasks/dp_c
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...);}
template<typename... T>
void send(T&&... args) { ((cout << args << " "), ...);cout<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

int32_t main(){
    fastio;
    int n;cin>>n;
    vector<vector<int>> dp(n+1,3);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c;
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]});
}