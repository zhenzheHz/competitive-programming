// Problem : https://atcoder.jp/contests/dp/tasks/dp_a
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
    vector<int> h(n+1),dp(n+1);
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    dp[1] = h[1];
    dp[2] = h[1] + abs(h[2] - h[1]);
    for(int i=3;i<=n;i++){
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]),dp[i-2] + abs(h[i-2] - h[i]));
    }
    cout << dp[n] << '\n';
}