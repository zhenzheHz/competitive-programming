#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 3e5+5;
int n,a[MAXN];

struct Node {
    int Min, sum;
};

struct SegTree {

    #define ls (p<<1)
    #define rs (p<<1|1)

    Node sg[MAXN<<2];

    int query(int l, int r, int p, int Min) {
        if(l == r) return min(sg[p].Min, Min);
        int mid = (l+r)>>1;
        if(Min <= sg[ls].Min) {
            return Min * (mid - l + 1) + query(mid+1, r, rs, Min);
        }
        else {
            return query(l, mid, ls, Min) + sg[p].sum - sg[ls].sum;
        }
    }

    void update(int l, int r, int p, int idx, int val) {
        if(l == r) return sg[p] = {val,val}, void();
        int mid = (l+r)>>1;
        if(idx <= mid) update(l, mid, ls, idx, val);
        else update(mid+1, r, rs, idx, val);
        // merge operation
        sg[p].Min = min(sg[ls].Min, sg[rs].Min);
        sg[p].sum = sg[ls].sum + query(mid+1, r, rs, sg[ls].Min);
    }

    #undef ls
    #undef rs
    
} tree;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int r = 1; r <= n; r++) {
        tree.update(0, n, 1, a[r], r);
        ans += tree.sg[1].sum;
    } 
    return cout<<ans, 0;
}