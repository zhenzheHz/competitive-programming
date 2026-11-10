#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct St {
    int a,b,c,d,e;
    St operator-(const St &cmp) const { 
        return {abs(a-cmp.a), abs(b-cmp.b), abs(c-cmp.c), abs(d-cmp.d), abs(e-cmp.e)};
    }
    int get() {
        return max({a,b,c,d,e});
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k,ans = 0;
    cin >> n >> k;
    vector<St> p(n);
    for(auto &[a,b,c,d,e] : p) cin >> a >> b >> c >> d >> e;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            St tmp = p[i] - p[j];
            if(tmp.get() <= k) ans++;
        }
    }
    cout << ans;
}