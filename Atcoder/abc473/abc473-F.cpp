#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int MAXN = 5e5 + 5;

struct SegTree {
    struct Node {
        int sum = 0, pref = 0;
    };
    vector<Node> sg;

    SegTree() {
        sg.resize(MAXN << 2);
    }

    Node merge(const Node &L, const Node &R) {
        Node res;
        res.sum = L.sum + R.sum;
        res.pref = min(L.pref, L.sum + R.pref);
        return res;
    }

    void update(int l, int r, int p, int idx, int val) {
        if (l == r) return sg[p].sum = sg[p].pref = val, void();
        int mid = (l + r) >> 1;
        if (idx <= mid) update(l, mid, p << 1, idx, val);
        else update(mid + 1, r, p << 1 | 1, idx, val);
        sg[p] = merge(sg[p << 1], sg[p << 1 | 1]);
    }

    Node query(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return sg[p];
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(l, mid, p << 1, ql, qr);
        if (ql > mid)  return query(mid + 1, r, p << 1 | 1, ql, qr);
        return merge(query(l, mid, p << 1, ql, qr), query(mid + 1, r, p << 1 | 1, ql, qr));
    }
};

SegTree tree;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, q;
    string str;
    if (!(cin >> n >> str >> q)) return 0;
    
    for (int i = 0; i < (int)str.size(); i++) {
        int sgn = (str[i] == 'A' ? 1 : -1);
        tree.update(1, n, 1, i + 1, sgn);
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            char c;
            cin >> i >> c;
            tree.update(1, n, 1, i, (c == 'A' ? 1 : -1));
        } else {
            int l, r;
            cin >> l >> r;
            cout << (tree.query(1, n, 1, l, r).pref >= 0 ? "Yes\n" : "No\n");
        }
    }
    return 0;
}