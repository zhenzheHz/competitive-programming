// Problem : https://atcoder.jp/contests/dp/tasks/dp_h
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

static constexpr int mod = 1e9+7;

int32_t main(){
    fastio;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            dp[i][j] = (c == '.');
        }
    }
    for(int i=0;i<n;i++){
        if(dp[i][0] == 0){
            for(int j=i;j<n;j++)dp[j][0] = 0;
        }
    }
    for(int j=0;j<m;j++){
        if(dp[0][j] == 0){
            for(int i=j;i<m;i++){
                dp[0][i] = 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j] == 0)continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][m-1];
}