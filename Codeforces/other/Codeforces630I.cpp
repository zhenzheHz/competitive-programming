// Problem : https://codeforces.com/contest/630/problem/I
// Tags : Math
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a * fp(a,b-1);
    int h = fp(a,b>>1);
    return h * h;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int k = 2*n-2;
    int ans = 0;
    for(int i=2;i<=n-2;i++) {
        int left = 3 * fp(4,i-2);
        int right =  3 * fp(4,(k - (i+n-1)-1));
        ans += left * right * 4;
    }
    ans += fp(4,k-n+1-1) * 3 * 2;
    cout << ans << '\n';
}