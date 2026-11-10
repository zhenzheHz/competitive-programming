// Problem : https://codeforces.com/contest/598/problem/B
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    while(n--) {
        int l,r,k;
        cin >> l >> r >> k;
        k %= (r-l+1);
        string front = s.substr(0,l-1), back = s.substr(r);
        string x = s.substr(r-k,k), y = s.substr(l-1,r-l+1-k);
        //cout << x << '\n' << y << '\n';
        s = front + x + y + back;
    }
    return cout<<s,0;
}