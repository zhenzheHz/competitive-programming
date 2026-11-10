// Problem : https://atcoder.jp/contests/abc389/tasks/abc389_e
// Tags : Binary Search, Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
typedef __int128 int128_t;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t n;
    int64_t m;
    cin >> n >> m;
    vector<int64_t> p(n);
    for(int &i : p) cin >> i;
    int64_t get = 0;
    function<bool(int)> check = [&](int x) {
        int128_t total = 0; get = 0;
        for(int i=0;i<n;i++) {
            int128_t k = (x/p[i] + 1) / 2;
            total += k * k *p[i];
            if(total > m) return false;
            get += k;
        }
        return true;
    };
    int l = 1, r = m+1;
    while(l+1!=r) {
        int mid = (l+r)>>1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    get = 0;
    vector<int128_t> more(n,(int128_t) 0);
    for(int i=0;i<n;i++) {
        int64_t k = (l/p[i] + 1) / 2;
        m -= k * k * p[i];
        get += k;
        more[i] = (k << 1 | 1) * p[i];
    }
    sort(more.begin(),more.end());
    for(int i=0;i<n;i++) {
        if(more[i] <= m) 
            get += 1, m -= more[i];
    }
    return cout << get << '\n',0;
}