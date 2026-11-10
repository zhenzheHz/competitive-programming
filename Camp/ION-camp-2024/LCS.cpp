// Problem : https://atcoder.jp/contests/dp/tasks/dp_f
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
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    vector<vector<pair<int,int>>> state(a.size()+1,vector<pair<int,int>>(b.size()+1,{-1,-1}));
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                state[i][j] = {i-1,j-1};
            }else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                state[i][j] = {i-1,j};
            }else{
                dp[i][j] = dp[i][j-1];
                state[i][j] = {i,j-1};
            }
        }
    }
    vector<char> ans;
    int x = a.size(),y = b.size();
    while(x != 0 && y != 0){
        pair<int,int> pre = state[x][y];
        if(pre.first < x && pre.second < y){
            ans.push_back(a[x-1]);
        }
        x = pre.first;
        y = pre.second;
    }
    reverse(all(ans));
    for(auto &c : ans){
        cout << c;
    }
}