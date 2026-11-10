// Problem : https://codeforces.com/problemset/problem/914/D
// Tags : Segment Tree
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e5+5;
int sg[MAXN<<2], arr[MAXN];

#define m ((l+r)>>1)

void build(int l, int r, int p) {
    if(l == r) return sg[p] = arr[l],void();
    build(l,m,p<<1), build(m+1,r,p<<1|1);
    sg[p] = __gcd(sg[p<<1], sg[p<<1|1]);
}

void update(int l,int r,int p,int idx, int val) {
    if(l == r) return sg[p] = arr[idx] = val,void();
    if(idx <= m) update(l,m,p<<1,idx,val);
    else update(m+1,r,p<<1|1,idx,val);
    sg[p] = __gcd(sg[p<<1], sg[p<<1|1]);
}

int getGCD(int l,int r,int p,int ql,int qr) {
    if(ql <= l && r <= qr) return sg[p];
    int result = 0;
    if(ql <= m) result = __gcd(result, getGCD(l,m,p<<1,ql,qr));
    if(m < qr) result = __gcd(result, getGCD(m+1,r,p<<1|1,ql,qr));
    return result;
}

bool guess(int l,int r,int p,int ql,int qr,int x) {
    if(l == r) return 1;
    int left_gcd = x, right_gcd = x;
    if(ql <= m) left_gcd = getGCD(l,r,p,ql,m);
    if(m < qr) right_gcd = getGCD(l,r,p,m+1,qr);
    left_gcd = __gcd(left_gcd, x);
    right_gcd = __gcd(right_gcd, x);
    if(left_gcd != x && right_gcd != x) return 0;
    if(left_gcd == x && right_gcd == x) return 1;
    if(left_gcd == x) return guess(l,m,p<<1,ql,qr,x);
    if(right_gcd == x) return (m+1,r,p<<1|1,ql,qr,x);
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    build(1,n,1);
    cin >> q;
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int L,R,x;
            cin >> L >> R >> x;
            cout << (guess(1,n,1,L,R,x)?"YES\n" : "NO\n");
        }else {
            int i,v;
            cin >> i >> v;
            update(1,n,1,i,v);
        }
    }
    return 0;
}