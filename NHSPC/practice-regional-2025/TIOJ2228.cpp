// Problem : https://tioj.ck.tp.edu.tw/problems/2228
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3e5+5;
struct Modify {
    int l,r,pos,tag;
    bool operator<(const Modify &cmp) const {
        return pos < cmp.pos;
    }
};
struct Segment_Tree {
    int sg[MAXN<<2], lazy[MAXN<<2];
    #define m ((l+r)>>1)
    void push(int l,int r,int p) {
        if(lazy[p] == 0 || l == r) return;
        sg[p<<1] += lazy[p];
        sg[p<<1|1] += lazy[p];
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
        lazy[p] = 0;
    }
    void update(int l,int r,int p,int ql,int qr,int x) {
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            sg[p] += x;
            lazy[p] += x;
            return;
        }
        push(l,r,p);
        update(l,m,p<<1,ql,qr,x);
        update(m+1,r,p<<1|1,ql,qr,x);
        sg[p] = max(sg[p<<1], sg[p<<1|1]);
    }
    void update(int ql,int qr,int x) {
        update(1,MAXN,1,ql,qr,x);
    }
    int query() {
        return sg[1];
    }
    #undef m
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Modify> tags;
    vector<int> handle, px(n), py(n), w(n);
    for(int i=0;i<n;i++) {
        int x,y,r;
        cin >> x >> y >> r >> w[i];
        handle.push_back(x+y-r);
        handle.push_back(x+y+r);
        px[i] = y - x - r;
        py[i] = y - x + r;
    }
    vector<int> copy(handle.begin(),handle.end());
    sort(copy.begin(),copy.end());
    copy.resize(unique(copy.begin(),copy.end()) - copy.begin());
    for(int i=0;i<(int) handle.size();i+=2) {
        int tmp1 = lower_bound(copy.begin(),copy.end(),handle[i]) - copy.begin() + 1;
        int tmp2 = lower_bound(copy.begin(),copy.end(),handle[i+1]) - copy.begin() + 1;
        if(tmp1 > tmp2) swap(tmp1,tmp2);
        tags.push_back({tmp1,tmp2,px[i>>1],w[i>>1]});
        tags.push_back({tmp1,tmp2,py[i>>1]+1,(-1)*w[i>>1]});
    }
    sort(tags.begin(),tags.end());
    Segment_Tree SGT;
    int ans = 0;
    for(auto &[l,r,pos,tag] : tags) {
        SGT.update(l,r,tag);
        ans = max(ans, SGT.query());
        // cout << l << ' ' << r << ' ' << pos << ' ' << tag << '\n';
    }
    return cout<<ans<<'\n',0;
}