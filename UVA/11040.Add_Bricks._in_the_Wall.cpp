// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=e583
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int Pyramid[10][10];
void Setting(int i,int j) {
    Pyramid[i+2][j+1] = (Pyramid[i][j] - Pyramid[i+2][j] - Pyramid[i+2][j+2]) / 2;
    Pyramid[i+1][j] = Pyramid[i+2][j] + Pyramid[i+2][j+1];
    Pyramid[i+1][j+1] = Pyramid[i+2][j+1] + Pyramid[i+2][j+2];
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        for(int i=1;i<=5;i++) {
            for(int j=1;j<=i;j++) {
                cin >> Pyramid[2*i-1][2*j-1];
            }
        }
        for(int i=1;i<=4;i++) {
            for(int j=1;j<=i;j++) {
                // layer i & No.j
                Setting(2*i-1,2*j-1);
            }
        }
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=i;j++) {
                cout << Pyramid[i][j] << " \n"[j==i];
            }
        }
    }
}