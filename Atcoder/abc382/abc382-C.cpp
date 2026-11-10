// Problem : https://atcoder.jp/contests/abc382/tasks/abc382_c
// Tags : Prefix
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<int> cus(n), sushi(m), pre_min(n+1);
    for(int &i : cus) cin >> i;
    for(int &i : sushi) cin >> i;
    pre_min[0] = cus[0];
    for(int i=1;i<=n;i++) pre_min[i] = min(pre_min[i-1],cus[i-1]);
    for(int &rk : sushi) {
        int l = 0, r = n+1;
        while(l+1!=r) {
            int m = (l+r)>>1;
            if(pre_min[m] > rk) l = m;
            else r = m;
        }
        cout << (r == n+1? -1 : r) <<'\n';
    }
    return 0;
}