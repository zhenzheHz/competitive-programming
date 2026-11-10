// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2228
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3e5+5;
struct Tag {
    int l,r,pos,w;
    bool operator<(const Tag &cmp) const {
        return pos < cmp.pos;
    }
};
struct Segment_Tree {
    int sg[MAXN<<2], lazy[MAXN<<2];
    #define m ((l+r)>>1)
    void push(int l,int r,int p) {
        if(lazy[p] == 0 || l == r) return;
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
        sg[p<<1] += lazy[p];
        sg[p<<1|1] += lazy[p];
        lazy[p] = 0;
    }
    void update(int l,int r,int p,int ql,int qr,int val) {
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazy[p] += val;
            sg[p] += val;
            return;
        }
        push(l,r,p);
        update(l,m,p<<1,ql,qr,val);
        update(m+1,r,p<<1|1,ql,qr,val);
        sg[p] = max(sg[p<<1], sg[p<<1|1]);;
    }
    void update(int l,int r,int x) {
        update(1,MAXN,1,l,r,x);
    }
    int query() { return sg[1]; }
    #undef m
};

Segment_Tree SGT;
vector<Tag> tags;
int w[MAXN],px[MAXN],py[MAXN];

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> idx;
    for(int i = 0; i < n; i++) {
        int x,y,r;
        cin >> x >> y >> r >> w[i];
        idx.push_back(x+y-r);
        idx.push_back(x+y+r);
        px[i] = y-x-r, py[i] = y-x+r;
    }
    vector<int> copy = idx;
    sort(copy.begin(), copy.end());
    copy.resize(unique(copy.begin(),copy.end())-copy.begin());
    for(int i = 0; i < (int) idx.size(); i+=2) {
        int p = lower_bound(copy.begin(),copy.end(),idx[i]) - copy.begin() + 1;
        int q = lower_bound(copy.begin(),copy.end(),idx[i+1]) - copy.begin() + 1;
        if(p > q) swap(p,q);
        tags.push_back({p,q,px[i>>1],w[i>>1]});
        tags.push_back({p,q,py[i>>1]+1,(-1)*w[i>>1]}); 
    }
    sort(tags.begin(), tags.end());
    int ans = 0;
    for(auto [l,r,h,w] : tags) {
        SGT.update(l,r,w);
        ans = max(ans,SGT.query());
    }
    return cout << ans, 0;
}