// Problem : https://www.luogu.com.cn/problem/P1494
// Tag : 莫隊
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
int color[MAXN], cnt[MAXN];
pair<int,int> out[MAXN];
int com = 0;
void add(int x) {
    cnt[x]++;
    if(cnt[x]) com += 2*cnt[x], com -= 2;
}
void del(int x) {
    if(cnt[x]) com -= 2*(cnt[x]-1);
    cnt[x]--;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    S = n / sqrt(q);
    for(int i=0;i<n;i++) {
        cin >> color[i];
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
        while(l > ql) add(color[--l]);
        while(r < qr) add(color[++r]);
        while(l < ql) del(color[l++]);
        while(r > qr) del(color[r--]);
        int len = qr - ql + 1;
        if(l == r || com == 0) out[qi] = {0,1};
        else {
            int gcd = __gcd(com,len*len-len);
            out[qi] = {com/gcd,len*(len-1)/gcd};
        };
    }
    for(int i=0;i<q;i++) {
        cout << out[i].first << "/" << out[i].second << '\n';
    }
    return 0;
}