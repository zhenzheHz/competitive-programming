// Author : Zhenzhe
// Time : 2024 / 10 / 14
// Problem : https://zerojudge.tw/ShowProblem?problemid=a518
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t from, to;
    while(cin >> from >> to) {
        if(from == -1 || to == -1) break;
        int32_t temp = abs(from-to);
        cout << min(temp,100-temp) << '\n';
    }
}