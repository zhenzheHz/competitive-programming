// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c123
#include <bits/stdc++.h>
using namespace std;
static constexpr int MAXN = 1005;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        if(n == 0) break;
        while(true) {
            int test[MAXN];
            bool next_case = false;
            for(int i=0;i<n;i++) {
                cin >> test[i];
                if(test[i] == 0) {
                    next_case = true;
                    break;
                }
            }
            if(next_case) {
                cout << '\n';
                break;
            }
            stack<int> station;
            int check = 0;
            for(int i=1;i<=n;i++) {
                station.push(i);
                while(station.size() && station.top() == test[check]) {
                    check += 1;
                    station.pop();
                }
            }
            if(check == n) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}