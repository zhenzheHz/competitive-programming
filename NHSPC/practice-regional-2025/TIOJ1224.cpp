// Problem : https://tioj.ck.tp.edu.tw/problems/1224
// Tag : 線段樹 ＋ 掃描線
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXR = 1e6+5, MAXN = 1e5+5;
struct Rec {
    int l,r,k,t;
};
struct Segment_Tree {
    int sg[MAXR<<2], lazy[MAXR<<2];
    #define m ((l+r)>>1)
    void pull(int l,int r,int p) {
        if(lazy[p] > 0) sg[p] = r-l+1;
        else if(l == r) sg[p] = 0;
        else sg[p] = sg[p<<1] + sg[p<<1|1];
    }
    void update(int l,int r,int p,int ql,int qr,int x) {
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazy[p] += x;
            pull(l,r,p);
            return;
        }
        update(l,m,p<<1,ql,qr,x);
        update(m+1,r,p<<1|1,ql,qr,x);
        pull(l,r,p);
    }
    int query() {return sg[1];}
    #undef m
};
int n;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    vector<Rec> tags;
    for(int i=0;i<n;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a++;
        tags.push_back({a,b,c,1});
        tags.push_back({a,b,d,-1});
    }
    sort(tags.begin(),tags.end(),[&](Rec a,Rec b) {
        return a.k < b.k;
    });
    Segment_Tree SGT;
    int cur = tags[0].k;
    int64_t ans = 0;
    for(auto [l,r,ptr,tag] : tags) {
        ans += 1LL * SGT.query() * (ptr - cur);
        // cout << SGT.query() * (ptr - cur) << ' ';
        cur = ptr;
        // cout << SGT.query() << ' ';
        // cout << l << ' ' << r << ' ' << SGT.query() << '\n';
        SGT.update(1,MAXR,1,l,r,tag);
    }
    cout << ans;
}