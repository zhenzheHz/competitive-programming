#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int div(int x) {
    int mn = 1e18+5;
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            mn = min(mn,i + x/i);
        }
    }
    return mn;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x,y;
    cin >> x >> y;
    int p = 3*x;
    int c = sqrt(p);
    //cout << c << '\n';
    if(c*c == p) cout << c + c + 1 + y;
    else if(c * (c+1) < p) cout << c + 1 + c + 1 +y + 1;
    else cout << c + 1 + c + y + 1;
}