// Problem : https://cses.fi/problemset/task/1190
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

struct node{
    int pre,suf,sum,ans;
    void pull(int x){
        pre = suf = sum = ans = x;
    }
    node operator+(const node &right){
        node res;
        res.pre = max(pre,sum+right.pre);
        res.suf = max(right.suf,suf+right.sum);
        res.sum = sum + right.sum;
        res.ans = max({ans,right.ans,suf+right.pre});
        return res;
    }
};
#define ls (p<<1)
#define rs ((p<<1)+1)
#define m ((l+r)>>1)

static constexpr int N = 2e5+5;
vector<node> sg(N<<2);
vector<int> arr(N);

void update(int l,int r,int p,int idx){
    if(l == r){
        sg[p].pull(arr[idx]);
        return;
    }
    if(idx<=m)update(l,m,ls,idx);
    else update(m+1,r,rs,idx);
    sg[p] = sg[ls]+sg[rs];
}

int32_t main(){
    int n,q;
    get(n,q);
    for(int i=1;i<=n;i++){
        get(arr[i]);
        update(1,n,1,i);
    }
    while(q--){
        int i,x;
        get(i,x);
        arr[i] = x;
        update(1,n,1,i);
        send(max(sg[1].ans,(int64_t)0));
    }
}