#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define lson (2*pos)
#define rson (2*pos+1)
#define len (right-left+1)
#define N 200005
int a[4*N],lazy[4*N],info[4*N];
inline void build(int left,int right,int pos){
    if(left == right){
        info[pos] = a[left];
        return;
    }
    int mid = (left+right)/2;
    build(left,mid,lson);
    build(mid+1,right,rson);
    info[pos] = info[lson]+info[rson];
}
inline void propagate(int left,int right,int pos){
    if(lazy[pos]){
        info[pos] += lazy[pos]*(right-left+1);
        if(left!=right){
            lazy[lson] += lazy[pos];
            lazy[rson] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    return;
}
inline void modify(int left,int right,int ql,int qr,int pos,int val){
    propagate(left,right,pos);
    if(left>right||right<ql||left>qr)return;
    if(ql<=left&&right<=qr){
        info[pos] += val*(right-left+1);
        if(left != right){
            lazy[lson] += val;
            lazy[rson] += val;
        }
        return;
    }
    int mid = (left+right)/2;
    modify(left,mid,ql,qr,lson,val);
    modify(mid+1,right,ql,qr,rson,val);
    info[pos] = info[lson] + info[rson];
}
inline int query(int left,int right,int ql,int qr,int pos){
    if(left>qr||right<ql)return 0;
    if(ql<=left&&right<=qr){
        return info[pos];
    }
    int mid = (left+right)/2;
    return query(left,mid,ql,qr,lson)+query(mid+1,right,ql,qr,rson);
}
signed main(void){
    int n,q;cin>>n>>q;
    for(int i = 1;i<=n;i++)cin>>a[i];
    build(1,n,1);
    for(int i = 1;i<=4*n;i++)lazy[i] = 0;
    for(int i = 0;i<q;i++){
        int cmd;cin>>cmd;
        if(cmd == 1){
            int a,b,x;cin>>a>>b>>x;
            modify(1,n,a,b,1,x);
        }
        if(cmd == 2){
            int a,b;cin>>a>>b;
            cout << query(1,n,a,b,1);
            cout << '\n';
        }
    }
}
