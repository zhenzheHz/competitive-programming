#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int n,x;cin>>n>>x;
    vector<int> prices(n),pages(n);
    for(int &price : prices) cin>>price;
    for(int &page : pages) cin>>page;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(prices[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-prices[i-1]]+pages[i-1]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][x];
}
