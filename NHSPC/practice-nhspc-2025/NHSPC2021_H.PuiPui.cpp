// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2258
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6+5;
int n,k,p,h[MAXN];
bool check(int thr) {
    
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k >> p;
    int l = -1, r = -1;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        r = max(r, h[i]+1);
    }
    sort(h+1, h+n+1);
    while(l+1 != r) {
        int mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }

}