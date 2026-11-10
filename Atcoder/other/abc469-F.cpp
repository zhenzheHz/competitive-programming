// Tags : MST
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;

struct Dsu {
    vector<int> pa;
    void init(int n) {
        pa.resize(n);
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) {
        if (x == pa[x]) return x;
        return pa[x] = find(pa[x]);
    }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return 0;
        pa[a] = b;
        return 1;
    }
};

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,MAXA = -1;
    cin >> n;
    vector<int> p(n), idx;
    for(int &x : p) {
        cin >> x;
        MAXA = max(MAXA, x+1);
    }
    idx.resize(MAXA, -1);
    for(int i = 0; i < n; i++) {
        idx[p[i]] = i;
    }
    Dsu dsu;
    dsu.init(n);
    int sum = 0, cnt = 0;
    for(int gcd = MAXA; gcd >= 1; gcd--){
        int f = -1;
        for(int k = gcd; k < MAXA; k += gcd) {
            if(idx[k] == -1) continue;
            if(f == -1) f = idx[k];
            else {
                if(dsu.merge(f, idx[k])) {
                    sum += gcd;
                    cnt++;
                }
            }
            if(cnt >= n-1) break;
        }
    }
    cout << sum << '\n';
}