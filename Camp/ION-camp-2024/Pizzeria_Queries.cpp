// Problem : https://cses.fi/problemset/task/2206
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...);}
template<typename... T>
void send(T&&... args) { ((cout << args << " "), ...);cout<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

#define m ((l+r)>>1)
#define ls (p<<1)
#define rs ((p<<1)+1)

static constexpr int N = 2e5+5;
vector<int> arr(N);
class Segment_tree{
    private:
        vector<int> tree;
    public:
        explicit Segment_tree(int n){
            tree.resize((n+1)<<2,1e18);
        }

        void pull(int p){
            tree[p] = min(tree[ls],tree[rs]);
        }

        void update(int l,int r,int p,int idx,int v){
            if(l == r){
                tree[p] = v;
                return;
            }
            if(idx<=m)update(l,m,ls,idx,v);
            else update(m+1,r,rs,idx,v);
            pull(p);
        }

        int query(int l,int r,int p,int ql,int qr){
            if(ql<=l&&r<=qr)return tree[p];
            int res = 1e18;
            if(ql<=m)res = min(res,query(l,m,ls,ql,qr));
            if(m<qr)res = min(res,query(m+1,r,rs,ql,qr));
            return res;
        }
};

int32_t main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    Segment_tree left(n),right(n);
    for(int i=1;i<=n;i++){
        left.update(1,n,1,i,arr[i]-i);
        right.update(1,n,1,i,arr[i]+i);
    }
    while(q--){
        int op;cin>>op;
        if(op == 1){
            int idx,x;
            cin>>idx>>x;
            arr[idx] = x;
            left.update(1,n,1,idx,x-idx);
            right.update(1,n,1,idx,x+idx);
        }else{
            int k;cin>>k;
            cout << min(left.query(1,n,1,1,k)+k,right.query(1,n,1,k,n)-k) << '\n';
        }
    }
}