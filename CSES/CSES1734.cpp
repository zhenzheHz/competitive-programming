// Problem : https://cses.fi/problemset/task/1734
// Tag : 莫隊
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, S = 450;
struct Query {
    int l,r,id;
    bool operator<(const Query &cmp) const {
        if(l / S == cmp.l / S) return (l / S & 1? r < cmp.r : r > cmp.r);
        return l < cmp.l;
    }
};

int cnt[MAXN], ans = 0;
void add(int x) {
    if(cnt[x] == 0) ans++;
    cnt[x]++;
}
void del(int x) {
    cnt[x]--;
    if(cnt[x] == 0) ans--;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int> tmp(arr.begin(),arr.end());
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end()) - tmp.begin());
    for(int i=0;i<n;i++) {
        arr[i] = lower_bound(tmp.begin(),tmp.end(),arr[i]) - tmp.begin();
    }
    vector<Query> query(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        a--, b--;
        query[i] = {a,b,i};
    }
    sort(query.begin(),query.end());
    vector<int> tp(q);
    int l = 1, r = 0;
    for(int i=0;i<q;i++) {
        const auto &[ql,qr,qi] = query[i];
        while(l > ql) add(arr[--l]);
        while(r < qr) add(arr[++r]);
        while(l < ql) del(arr[l++]);
        while(r > qr) del(arr[r--]);
        tp[qi] = ans;
    }
    for(int &as : tp) cout << as << '\n';
}