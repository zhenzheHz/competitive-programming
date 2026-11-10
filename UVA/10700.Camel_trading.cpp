// Author : Zhenzhe
// Time : 2024 / 11 / 03
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    string eval,tmp = "";
    int cs = 0;
    cin >> eval;
    stack<int> stk;
    eval.push_back('*');
    for(auto sign : eval) {
        if(isdigit(sign)) {
            tmp.push_back(sign);
        }else {
            int now = stoi(tmp);
            tmp = "";
            if(sign == '+') {
                cs += now;
            }else {
                stk.push(cs+now);
                cs = 0;
            }
        }
    }
    int Maximum = 1;
    while(!stk.empty()) {
        Maximum *= stk.top();
        stk.pop();
    }
    eval.pop_back();
    eval.push_back('+');
    cs = 1;
    for(auto sign : eval) {
        if(isdigit(sign)) {
            tmp.push_back(sign);
        }else {
            int now = stoi(tmp);
            tmp = "";
            if(sign == '*') {
                cs *= now;
            }else {
                stk.push(cs*now);
                cs = 1;
            }
        }
    }
    int Minimum = 0;
    while(!stk.empty()) {
        Minimum += stk.top();
        stk.pop();
    }
    cout << "The maximum and minimum are " << Maximum << " and " << Minimum << ".\n";
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}