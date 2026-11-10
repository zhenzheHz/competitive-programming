// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c125
#include <bits/stdc++.h>
using namespace std;
using point = pair<int,int>;
static constexpr int MAXN = 205;
static constexpr int INF = 0x3f3f3f;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int CASE = 1, n;
    while(cin >> n) {
        if(n == 0) break;
        cout << "Scenario #" << CASE++ << "\n";
        point stone[MAXN];
        for(int i=0;i<n;i++) {
            cin >> stone[i].first >> stone[i].second;
        }
        int dp[MAXN][MAXN];
        memset(dp,INF,sizeof(dp));
        for(int i=0;i<n;i++) dp[i][i] = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = dp[j][i] = pow(stone[i].first - stone[j].first,2) + pow(stone[i].second - stone[j].second,2); 
            }
        }
        for(int auxi = 0; auxi < n; auxi++) {
            for(int from = 0; from < n; from++) {
                for(int to = 0; to < n; to++) {
                    dp[from][to] = min(dp[from][to],max(dp[from][auxi],dp[auxi][to]));
                }
            }
        }
        double distance = sqrt(dp[0][1]);
        cout << "Frog Distance = ";
        cout << fixed << setprecision(3) << distance << "\n\n";
    }
}