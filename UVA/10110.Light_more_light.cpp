// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=d111
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve(int test);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    while(cin >> test && test != 0) {
        // find the quantity of factors(N) = phi(N)
        // if phi(N) % 2 == 0  => is light
        // and only squared numbers satisfy
        // because if N has factor x,and it has N/x
        int l = -1, r = test + 1;
        while(l + 1 != r) {
            int m = (l+r)>>1;
            if(m*m <= test) l = m;
            else r = m;
        }
        cout << ((l*l == test)? "yes\n" : "no\n");
    }
}