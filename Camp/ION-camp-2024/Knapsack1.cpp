// Problem : https://atcoder.jp/contests/dp/tasks/dp_c
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
    int n,x;
    cin>>n>>x;
    vector<int>w(n+1),v(n+1);
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(w[i] > j)dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout << dp[n][x];
}