// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=e183
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
unordered_map<int,int> memo;
int Recursion(int x) {
    if(memo.find(x) != memo.end()) return memo[x];
    if(x == 1) return 1;
    if(x & 1) return 2 * Recursion((x+1)/2) - 2;
    else return 2 * Recursion(x/2);
}
signed main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    while(cin >> test && test != 0) {
        cout << Recursion(test) << '\n';
    }
}