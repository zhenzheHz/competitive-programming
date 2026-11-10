#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
    int a,b;
    cin >> a >> b;
    bool check = 0;
    if(a+b == 9) check = 1;
    if(a-b == 9) check = 1;
    if(a*b == 9) check = 1;
    if(a/b == 9 && a%b == 0) check = 1;
    cout << (check? "Nine\n" : "Nein\n");
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}