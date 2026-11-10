#include <bits/stdc++.h>
#define int int64_t
using namespace std;
#define f(x,y) (A+B*max(0LL,y-x)+C*max(0LL,x-y)+D*llabs(x-y))
int A,B,C,D;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,ans = 0;
    cin >> n >> A >> B >> C >> D;
    int prev = 1;
    for(int i=0;i<n;i++) {
        int nxt;
        cin >> nxt;
        ans += f(prev,nxt);
        // cout << f(prev,nxt);
        prev = nxt;
    }
    return cout << ans << '\n',0;
}