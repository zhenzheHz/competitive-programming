// Problem : https://zerojudge.tw/ShowProblem?problemid=c652
// Tag : 線段樹 + 開方操作
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3e5+5;
int n,q,arr[MAXN];
vector<int> sg;
vector<bool> one;
struct Segment_Tree {
    #define m ((l+r)>>1)
    void pull(int p) {
        sg[p] = sg[p<<1] + sg[p<<1|1];
        one[p] = one[p<<1] & one[p<<1|1];
    }
    void build(int l = 1,int r = n, int p = 1) {
        if(l == r) {
            sg[p] = arr[l];
            one[p] = (arr[l] == 1 || arr[l] == 0);
            return;
        }
        build(l,m,p<<1), build(m+1,r,p<<1|1);
        pull(p);
    }
    void update(int l,int r,int p,int ql,int qr) {
        if(one[p]) return;
        if(l == r) {
            sg[p] = sqrt(sg[p]);
            one[p] = (sg[p] <= 1);
            return;
        }
        if(ql <= m) update(l,m,p<<1,ql,qr);
        if(m < qr) update(m+1,r,p<<1|1,ql,qr);
        pull(p);
    }
    int query(int l,int r,int p,int ql,int qr) {
        if(ql <= l && r <= qr) return sg[p];
        int res = 0;
        if(ql <= m) res += query(l,m,p<<1,ql,qr);
        if(m < qr) res += query(m+1,r,p<<1|1,ql,qr);
        return res;
    }
    #undef m
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> q;
    sg.resize(4*n+4);
    one.resize(4*n+4);
    Segment_Tree SGT;
    for(int i=1;i<=n;i++) cin >> arr[i];
    SGT.build();
    while(q--) {
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 1) SGT.update(1,n,1,l,r);
        else cout << SGT.query(1,n,1,l,r) << '\n';
    }
    return 0;
}