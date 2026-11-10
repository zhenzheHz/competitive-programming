#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int N = 2e5+5;
vector<int> sg(N<<2),a(N);
#define m ((l+r)>>1)
#define ls (p<<1)
#define rs (p<<1)+1
void pull(int p){
    sg[p] = min(sg[ls],sg[rs]);
}
void bd(int l,int r,int p){
    if(l == r){
        sg[p] = a[l];return;
    }
    bd(l,m,ls);bd(m+1,r,rs);
    pull(p);
}
int qry(int l,int r,int p,int ql,int qr){
    if(ql<=l&&r<=qr)return sg[p];
    if(qr<=m)return qry(l,m,ls,ql,qr);
    else if(m<ql)return qry(m+1,r,rs,ql,qr);
    return min(qry(l,m,ls,ql,qr),qry(m+1,r,rs,ql,qr));
}
int32_t main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin >> a.at(i);
    }
    bd(1,n,1);
    while(q--){
        int a,b;cin>>a>>b;
        cout << qry(1,n,1,a,b) << '\n';
    }
}
