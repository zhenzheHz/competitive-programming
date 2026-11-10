// Problem : https://cses.fi/problemset/task/1076
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
int mapping[MAXN];
struct Segment_Tree {
    int sg[MAXN<<2];
    #define m ((l+r)>>1)
    void update(int l,int r,int p,int idx,int x) {
        if(l == r) return sg[p] += x,void();
        if(idx <= m) update(l,m,p<<1,idx,x);
        else update(m+1,r,p<<1|1,idx,x);
        sg[p] = sg[p<<1] + sg[p<<1|1];
    }
    void update(int i,int x) {
        update(1,MAXN,1,i,x);
    }
    int query(int l,int r,int p,int k) {
        if(l == r) return l;
        if(sg[p<<1] >= k) return query(l,m,p<<1,k);
        else return query(m+1,r,p<<1|1,k-sg[p<<1]);
    }
    int query(int k) {
        return query(1,MAXN,1,k);
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    vector<int> copy(arr.begin(),arr.end());
    sort(copy.begin(),copy.end());
    copy.resize(unique(copy.begin(),copy.end()) - copy.begin());
    for(int i=0;i<n;i++) {
        int rk = lower_bound(copy.begin(),copy.end(),arr[i]) - copy.begin() + 1;
        mapping[rk] = arr[i];
        arr[i] = rk;
    }
    Segment_Tree SGT;
    for(int i=0;i<k;i++) {
        SGT.update(arr[i],1);
    }
    int cur_l = 0;
    do {
        int tmp = SGT.query(k/2 + (k&1));
        cout << mapping[tmp] << ' ';
        SGT.update(arr[cur_l],-1);
        SGT.update(arr[cur_l+k],1);
        cur_l++;
    } while(cur_l + k <= n);
    return 0;
}