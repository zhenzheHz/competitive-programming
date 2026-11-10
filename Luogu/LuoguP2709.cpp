// Problem : https://www.luogu.com.cn/problem/P2709
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e4+5;
int S;
struct Query {
    int l,r,id;
    bool operator<(const Query &cmp) const {
        if(l / S == cmp.l / S) return (l / S & 1? r < cmp.r : r > cmp.r);
        return l < cmp.l;
    }
} query[MAXN];
int n , q, k, arr[MAXN], cnt[MAXN], tmp = 0, out[MAXN];
void add(int x) {
    cnt[x]++;
    tmp += (cnt[x] + cnt[x] - 1);
}
void del(int x) {
    tmp -= (cnt[x] + cnt[x] - 1);
    cnt[x]--;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> q >> k;
    S = n / sqrt(q);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<q;i++) {
        int l,r;
        cin >> l >> r;
        l--, r--;
        query[i] = {l,r,i};
    }
    sort(query,query+q);
    int l = 1, r = 0;
    for(int i=0;i<q;i++) {
        auto &[ql,qr,qi] = query[i];
        while(l > ql) add(arr[--l]);
        while(r < qr) add(arr[++r]);
        while(l < ql) del(arr[l++]);
        while(r > qr) del(arr[r--]);
        out[qi] = tmp;
    }
    for(int i=0;i<q;i++) {
        cout << out[i] << '\n';
    }
}