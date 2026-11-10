// Author : zhenzhe
// Time : 2026/09/19 20:39:06
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
static constexpr int MAXN = 2e5 + 5;

struct SegTree {
    vector<int> min_idx, max_idx, Min, Max;

    void init() {
        min_idx.resize(MAXN << 2);
        max_idx.resize(MAXN << 2);
        Min.resize(MAXN << 2, INF);
        Max.resize(MAXN << 2, -INF);
    }

    void merge(int p) {
        if(Min[p<<1] < Min[p<<1|1]) {
            Min[p] = Min[p<<1];
            min_idx[p] = min_idx[p<<1];
        }
        else {
            Min[p] = Min[p<<1|1];
            min_idx[p] = min_idx[p<<1|1];
        }

        if(Max[p<<1] > Max[p<<1|1]) {
            Max[p] = Max[p<<1];
            max_idx[p] = max_idx[p<<1];
        }
        else {
            Max[p] = Max[p<<1|1];
            max_idx[p] = max_idx[p<<1|1];
        }
    }

    void update(int l, int r, int p, int idx, int val) {
        if(l == r) {
            min_idx[p] = max_idx[p] = l;
            Min[p] = Max[p] = val;
            return;
        }
        int mid = (l+r) >> 1;
        if(idx <= mid) update(l, mid, p<<1, idx, val);
        else update(mid+1, r, p<<1|1, idx, val);
        merge(p);
    }

    pair<int, int> get_min(int l, int r, int p, int ql, int qr) {
        if(ql <= l && r <= qr) return {Min[p], min_idx[p]};
        int mid = (l+r) >> 1;
        if(qr <= mid) return get_min(l, mid, p<<1, ql, qr);
        if(mid < ql) return get_min(mid+1, r, p<<1|1, ql, qr);
        auto x = get_min(l, mid, p<<1, ql, qr);
        auto y = get_min(mid+1, r, p<<1|1, ql, qr);
        return x.first < y.first ? x : y;
    }

    pair<int, int> get_max(int l, int r, int p, int ql, int qr) {
        if(ql <= l && r <= qr) return {Max[p], max_idx[p]};
        int mid = (l+r) >> 1;
        if(qr <= mid) return get_max(l, mid, p<<1, ql, qr);
        if(mid < ql) return get_max(mid+1, r, p<<1|1, ql, qr);
        auto x = get_max(l, mid, p<<1, ql, qr);
        auto y = get_max(mid+1, r, p<<1|1, ql, qr);
        return x.first > y.first ? x : y;
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    SegTree sg;
    sg.init();
    vector<int> f(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
        sg.update(1,n,1,i,f[i]);
    }
    for(int i = 0; i < m; i++) {
        int l,r;
        cin >> l >> r;
        int _min_idx = sg.get_min(1,n,1,l,r).second;
        int _max_idx = sg.get_max(1,n,1,l,r).second;
        if (_min_idx != _max_idx) {
            sg.update(1,n,1,_min_idx,f[_max_idx]);
            sg.update(1,n,1,_max_idx,f[_min_idx]);
            swap(f[_min_idx], f[_max_idx]);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i==n];
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}