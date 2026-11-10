// Problem : https://cses.fi/problemset/task/1651
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
int n, q, arr[MAXN], sg[MAXN<<2], tag[MAXN<<2];
#define ls (p<<1)
#define rs (p<<1|1)
#define m ((l+r)>>1)
void mark(int l, int r, int p) {
    if(tag[p] == 0) return;
    sg[ls] += (m-l+1) * tag[p];
    sg[rs] += (r-m) * tag[p];
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
void update(int l, int r, int p, int ql, int qr, int val) {
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        sg[p] += (r-l+1) * val;
        tag[p] += val;
        return;
    }
    mark(l,r,p);
    if(ql <= m) update(l,m,ls,ql,qr,val);
    if(m < qr) update(m+1,r,rs,ql,qr,val);
    sg[p] = sg[ls] + sg[rs];
}
int get(int l, int r, int p, int ql, int qr) {
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) return sg[p];
    mark(l,r,p);
    int ans = 0;
    if(ql <= m) ans += get(l,m,ls,ql,qr);
    if(m < qr) ans += get(m+1,r,rs,ql,qr);
    return ans; 
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        update(1,n,1,i,i,arr[i]);
    }
    while(q--) {
        int op,x,a,b;
        cin >> op;
        if(op == 1) {
            cin >> a >> b >> x;
            update(1,n,1,a,b,x);
        }else {
            cin >> a;
            cout << get(1,n,1,a,a) << '\n';
        }
    }
}