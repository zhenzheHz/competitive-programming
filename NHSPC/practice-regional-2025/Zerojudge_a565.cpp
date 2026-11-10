// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=a565
// Tag :  101學年度 台北市 資訊學科能力競賽 2
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line, N;
    getline(cin, N);
    int n = stoi(N);
    while(n--) {
        getline(cin, line);
        int ans = 0;
        vector<int> stk;
        for(auto ch : line) {
            if(ch == '.') continue;
            if(ch == 'p') stk.push_back(0);
            if(ch == 'q') {
                if(stk.size() && stk.back() == 0) {
                    stk.pop_back();
                    ans += 1;
                } else {
                    stk.push_back(1);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}