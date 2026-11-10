// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=c010
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    vector<int> Array;
    while(cin >> test) {
        Array.push_back(test);
        sort(Array.begin(), Array.end());
        if(Array.size() & 1) {
            int index = Array.size() / 2;
            cout << Array[index] << '\n';
        }else {
            int index = Array.size() / 2;
            int ans = (Array[index-1] + Array[index]) / 2;
            cout << ans << '\n';
        }
    }
}