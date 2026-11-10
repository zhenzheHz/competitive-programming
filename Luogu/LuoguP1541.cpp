// Problem : https://www.luogu.com.cn/problem/P1541
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int cnt[5], num[355];
int dp[41][41][41][41];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> num[i];
    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = num[0];
    for(int a=0;a<=cnt[1];a++) {
        for(int b=0;b<=cnt[2];b++) {
            for(int c=0;c<=cnt[3];c++) {
                for(int d=0;d<=cnt[4];d++) {
                    int forth = a+b*2+c*3+d*4;
                    if(a) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a-1][b][c][d] + num[forth]);
                    if(b) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b-1][c][d] + num[forth]);
                    if(c) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c-1][d] + num[forth]);
                    if(d) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c][d-1] + num[forth]);
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
}