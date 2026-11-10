// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c060
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    array<int,9> c;
    int sign = 0;
    while(cin >> c[8]) {
        sign = 0;
        for(int i = 7; i >= 0; i--) cin >> c[i];
        for(int i = 0; i < 9; i++) {
            if(c[i] < 0) {
                sign |= (1 << i);
                c[i] = abs(c[i]);
            }
        }
        bool leader = false;
        for(int i = 8; i >= 0; i--) {
            if(c[i] == 0) continue;
            if(leader) {
                cout << ' ';
                cout << ((sign & (1<<i))? '-' : '+');
                cout << ' ';
            }
            else {
                leader = true;
                if(sign & (1<<i)) cout << '-';
            }
            if(i == 0) cout << c[i];
            else {
                if(c[i] != 1) cout << c[i];
                cout << 'x';
                if(i > 1) cout << '^' << i;
            }
        }
        if(!leader) cout << 0;
        cout << '\n';
    }
    return 0;
}