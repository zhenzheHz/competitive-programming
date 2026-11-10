// Problem : https://codeforces.com/contest/711/problem/B
// Tags : Implement
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1) return cout<<1,0;
    int grid[n][n];
    int x,y;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 0)
                x = i, y = j;
        }
    }
    int sigma = 0;
    int xc = (x+1)%n;
    for(int i=0;i<n;i++) sigma += grid[xc][i];

    for(int i=0;i<n;i++) {
        if(i == x) continue;
        int s = 0;
        for(int j=0;j<n;j++) {
            s += grid[i][j];
        }
        if(s != sigma) return cout<<-1,0;
    }

    for(int i=0;i<n;i++) {
        if(i == y) continue;
        int s = 0;
        for(int j=0;j<n;j++) {
            s += grid[j][i];
        }
        //cout << i << ' ' << s << '\n';
        if(s != sigma) return cout<<-1,0;
    }

    int sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++) {
        sum1 += grid[i][y];
    }
    if(sigma <= sum1) return cout<<-1,0;
    for(int i=0;i<n;i++) {
        sum2 += grid[x][i];
    }
    if(sigma <= sum1) return cout<<-1,0;
    if(sum1 != sum2) return cout<<-1,0;
    int sum3 = 0;
    for(int i=0;i<n;i++) {
        sum3 += grid[i][i];
    }
    if(x != y) {
        if(sigma != sum3) return cout<<-1,0;
    }else {
        if(sum1 != sum3) return cout<<-1,0;
    }
    int sum4 = 0;
    for(int i=0;i<n;i++) {
        sum4 += grid[i][n-1-i];
    }
    if(x+y == n-1) {
        if(sum4 != sum2) return cout<<-1,0;
    }else {
        if(sigma != sum4) return cout<<-1,0;
    }
    cout << sigma - sum1;
}