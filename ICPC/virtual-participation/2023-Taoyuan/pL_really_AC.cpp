// Author : ysh
// 2026/10/15 Thu 18:58:29
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int R = int(1e9) + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    if(n == 1) cout<<1;
    if(n == 2) cout<<2;
    if(n == 3) cout<<3;
    if(n == 4) cout<<4;
    if(n == 5) cout<<5;
    if(n == 6) cout<<6;
    if(n == 7) cout<<7;
    if(n == 8) cout<<8;
    if(n == 9) cout<<8;
    if(n == 10) cout<<5;
    if(n == 11) cout<<4;
    if(n == 12) cout<<6;
    if(n == 13) cout<<5;
    if(n == 14) cout<<7;
    if(n == 15) cout<<6;
    if(n == 16) cout<<8;
    if(n == 17) cout<<8;
    if(n == 18) cout<<9;
    if(n == 19) cout<<9;
    if(n == 20) cout<<10;
    if(n == 21) cout<<9;
    if(n == 22) cout<<11;
    if(n == 23) cout<<9;
    if(n == 24) cout<<12;
    if(n == 25) cout<<9;
    if(n == 26) cout<<13;
    if(n == 27) cout<<9;
    if(n == 28) cout<<14;
    if(n == 29) cout<<10;
    if(n == 30) cout<<15;

    if(n <= 30) return 0;

    if(n & 1) cout<<(((n - 11) >> 1) + 1) % R;
    else cout<<(n >> 1) % R;

    return 0;
}
