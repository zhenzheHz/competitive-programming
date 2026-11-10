// Author : Zhenzhe
// Time : 2024 / 10 / 18
// Problem : https://zerojudge.tw/ShowProblem?problemid=e580
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int row, col;
    while(cin >> row >> col) {
        if(row == 0 && col == 0) break;
        int A = min(row, col), B = max(row, col), ans = 0;
        if(A == 1) 
            ans = B;
        else if(A == 2) {
            int unit = B / 4, rest = min(2,B % 4); 
            ans = 4 * unit + 2 * rest;
            // cout << unit << ' ' << rest << '\n';
        }
        else 
            ans = A*B / 2 + A*B % 2;
        cout << ans << " knights may be placed on a "<< row <<" row " << col << " column board.\n";
    }
}