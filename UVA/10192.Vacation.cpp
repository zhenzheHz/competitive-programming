// Author : Zhenzhe
// Time : 2024 / 11 / 01
// Problem : https://zerojudge.tw/ShowProblem?problemid=d674
#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string father, mother;
    int CASE = 1;
    while(getline(cin,father)) {
        if(father == "#") break;
        getline(cin,mother);
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=father.size();i++) {
            for(int j=1;j<=mother.size();j++) {
                if(father[i-1] == mother[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << "Case #" << CASE++ << ": you can visit at most " << dp[father.size()][mother.size()] << " cities.\n";
    }
}