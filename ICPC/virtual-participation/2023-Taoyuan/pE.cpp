#include <bits/stdc++.h>
#include<slow>
#define int int64_t
using namespace std;
static constexpr int MAXN = 500;
#define all(i) i.begin(), i.end()

struct Segment_Tree {
    int sg[MAXN<<2], lazy[MAXN<<2];
    bool tag[MAXN<<2];
    #define m ((l+r)>>1)
    void push(int l,int r,int p) {
        if(!tag[p] || l == r) return;
        lazy[p<<1] = lazy[p<<1|1] = lazy[p];
        sg[p<<1] = sg[p<<1|1] = lazy[p];
        tag[p<<1] = tag[p<<1|1] = 1;
        tag[p] = 0;
    }
    void update(int l,int r,int p,int ql,int qr,int val) {
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            sg[p] = lazy[p] = val;
            tag[p] = 1;
            return;
        }
        push(l,r,p);
        update(l,m,p<<1,ql,qr,val);
        update(m+1,r,p<<1|1,ql,qr,val);
        sg[p] = max(sg[p<<1], sg[p<<1|1]);
    }
    int query(int l,int r,int p,int ql,int qr) {
        if(r < ql || qr < l) return LLONG_MIN;
        if(ql <= l && r <= qr) return sg[p];
        push(l,r,p);
        return max(query(l,m,p<<1,ql,qr), query(m+1,r,p<<1|1,ql,qr));
    }
    void update(int l,int r,int x) {
        update(1,MAXN,1,l,r,x);
    }
    int query(int l,int r) {
        return query(1,MAXN,1,l,r);
    }
	inline void dddebug() {
		re(i, 50) cerr<<sg[i]<<" ";
		cerr<<"\n";
	}
    #undef m
};

inline int offline(vc<array<int, 4>>&f) {
	vc<int>mark;
	repo(&i, f) re(j, 4) mark.push_back(i[j]);

	sort(all(mark));
	mark.resize(unique(all(mark)) - mark.begin());

	repo(&i, f) re(j, 4) i[j] = lower_bound(all(mark), j) - mark.begin();
	
	return mark.size();
}

signed main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(0);
	// int n,k;
	// cin >> n >> k;

	int n;cin>>n;
	while(n--) {
		int n, k;cin>>n>>k;
		
		vc<array<int, 4>>f(n);
		repo(&i, f) re(j, 4) cin>>i[j];

		int m = offline(f);

		Segment_Tree t;
		repo(&i, f) {
			auto now = t.query(i[1], i[3]);

			now += k;
			int det = i[2] - i[0];

			t.update(i[1], i[3], now + det);
		}

		t.dddebug();
		outl(t.query(0, m) - k);
	}
	return 0;
}
