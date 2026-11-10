// Problem : https://zerojudge.tw/ShowProblem?problemid=d794
// Tag : Segment_Tree
#include <bits/stdc++.h>
#define int int64_t
#define m ((l+r)>>1)
using namespace std;
struct Segment_Tree {
    size_t sz;
    vector<int> sg;
    void init(int k) {
        sz = k;
        sg.resize((k+1)<<2,0);
    }
    void update(int l,int r,int p,int idx,int x) {
        if(l == r) return sg[p] += x,void();
        if(idx <= m) update(l,m,p<<1,idx,x);
        else update(m+1,r,p<<1|1,idx,x);
        sg[p] = sg[p<<1] + sg[p<<1|1];
    }
    int query(int l,int r,int p,int ql,int qr) {
        if(ql<=l && r<=qr) return sg[p];
        if(r < ql || qr < l) return 0;
        int ans = 0;
        if(ql <= m) ans += query(l,m,p<<1,ql,qr);
        if(m < qr) ans += query(m+1,r,p<<1|1,ql,qr);
        return ans;
    }
};
void discretization(vector<int> &origin, size_t len) {
    vector<int> copy(origin.begin(),origin.end());
    sort(copy.begin(), copy.end());
    copy.resize(unique(copy.begin(),copy.end()) - copy.begin());
    for(int i=0;i<(int)len;i++) {
        origin[i] = lower_bound(copy.begin(),copy.end(),origin[i]) - copy.begin() + 1;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n) {
        Segment_Tree Tree;
        Tree.init(n);
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        discretization(arr, n);
        for(int i=0;i<n;i++) {
            Tree.update(1,n,1,arr[i],1);
            cout << Tree.query(1,n,1,arr[i],n) << '\n';
        }
    }
}