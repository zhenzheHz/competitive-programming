// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=e524
// Tag : 106學年度 彰雲嘉複賽 資訊學科能力 
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string N;
    getline(cin, N);
    int n = stoi(N);
    while(n--) {
        string a,b,x = "",y = "";
        getline(cin, a);
        getline(cin, b);
        for(auto ch : a) {
            if(isalpha(ch)) {
                if(islower(ch)) x.push_back(ch);
                else x.push_back('a' + ch - 'A');
            }
        }
        for(auto ch : b) {
            if(isalpha(ch)) {
                if(islower(ch)) y.push_back(ch);
                else y.push_back('a' + ch - 'A');
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << (x == y) << '\n';
    }
    return 0;
}