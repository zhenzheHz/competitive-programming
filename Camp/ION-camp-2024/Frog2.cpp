// Problem : https://atcoder.jp/contests/dp/tasks/dp_b
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
    int n,k;
    cin>>n>>k;
    vector<int> h(n+1),dp(n+1,0);
    for(int i=1;i<=n;i++)cin>>h[i];
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        int mn = 1e18;
        for(int p=1;p<=k;p++){
            if(i-p<=0)break;
            mn = min(mn,dp[i-p] + abs(h[i] - h[i-p]));
        }
        dp[i] = mn;
    }
    cout << dp[n];
}