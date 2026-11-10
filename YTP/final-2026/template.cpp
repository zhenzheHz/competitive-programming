#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define noTLE ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define debug(x) cerr << #x << " = " << x << "\n"
// #define all(x) (x.begin(), x.end())
// #define sz(x) ((int32_t) x.size())

int read(){
    int res = 0 , f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        res = res * 10 + ch - 48;
        ch = getchar();
    }
    return res * f;
}
void print(int x){
	if(x == 0){
        putchar(48);
        return;
    }
    int len = 0, dg[20];
    while (x > 0){
        dg[++len] = x % 10;
        x /= 10;
    }
    for (int i = len; i >= 1; --i)
        putchar(dg[i] + 48);
}


static constexpr int MOD = 998244353;
static constexpr int Mod = 1e9+7;
constexpr int64_t INF = 1e18+5;
const double PI = acos((double)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

// <== Data Structure ==>

struct DSU {
    int n;
    vector<int> p;
    DSU(int n = 0) : n(n), p(n, -1) {}

    int find(int u) {
        if (p[u] < 0) return u;
        return p[u] = find(p[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool merge(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (-p[x] < -p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }

    int size(int u) {
        return -p[find(u)];
    }

    // O(n) 
    vector<vector<int>> groups() {
        vector<int> root(n), sz(n);
        for (int i = 0; i < n; ++i) {
            root[i] = find(i);
            sz[root[i]]++;
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            res[i].reserve(sz[i]);
        }
        for (int i = 0; i < n; ++i) {
            res[root[i]].push_back(i);
        }
        vector<vector<int>> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!res[i].empty()) {
                ans.push_back(move(res[i]));
            }
        }
        return ans;
    }
};

template <class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz, log;
    vector<S> d;

    SegTree(int n) : SegTree(vector<S>(n + 1, e())) {}

    SegTree(const vector<S>& v) : n((int)v.size() - 1) {
        log = 0;
        while ((1 << log) <= n) log++;
        sz = 1 << log;
        d.assign(2 * sz, e());
        for (int i = 1; i <= n; ++i) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 1; --i) update(i);
    }

    void update(int k) {
        d[k] = op(d[2 * k], d[2 * k + 1]);
    }

    void set(int p, S x) {
        p += sz;
        d[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }

    S get(int p) const {
        return d[p + sz];
    }

    S query(int l, int r) const {
        S sml = e(), smr = e();
        l += sz; r += sz + 1;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const {
        return d[1];
    }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        if (l > n) return n;
        l += sz;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < sz) {
                    l = 2 * l;
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - sz - 1;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        if (r < 1) return 1;
        r += sz + 1;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < sz) {
                    r = 2 * r + 1;
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 1;
    }
};

struct LazySegTree {
    struct Node {
        long long sum = 0;
        long long mn = 0;
        long long mx = 0;
    };

    struct Tag {
        long long add = 0;
        long long assign = 0;
        bool is_assign = false;
    };

    int n, sz;
    vector<Node> tree;
    vector<Tag> lazy;

    Node merge_node(const Node& a, const Node& b) {
        return {a.sum + b.sum, min(a.mn, b.mn), max(a.mx, b.mx)};
    }

    LazySegTree(int n) : n(n) {
        sz = 1;
        while (sz <= n) sz <<= 1;
        tree.assign(2 * sz, {0, (long long)2e18, (long long)-2e18});
        lazy.resize(2 * sz);
    }

    LazySegTree(const vector<long long>& a) : n((int)a.size() - 1) {
        sz = 1;
        while (sz <= n) sz <<= 1;
        tree.assign(2 * sz, {0, (long long)2e18, (long long)-2e18});
        lazy.resize(2 * sz);
        for (int i = 1; i <= n; ++i) {
            tree[sz + i] = {a[i], a[i], a[i]};
        }
        for (int i = sz - 1; i >= 1; --i) {
            tree[i] = merge_node(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void apply_tag(int k, int len, const Tag& t) {
        if (t.is_assign) {
            tree[k].sum = t.assign * len;
            tree[k].mn = t.assign;
            tree[k].mx = t.assign;
            lazy[k].assign = t.assign;
            lazy[k].add = 0;
            lazy[k].is_assign = true;
        }
        if (t.add != 0) {
            tree[k].sum += t.add * len;
            tree[k].mn += t.add;
            tree[k].mx += t.add;
            lazy[k].add += t.add;
        }
    }

    void push(int k, int len) {
        if (!lazy[k].is_assign && lazy[k].add == 0) return;
        apply_tag(2 * k, len / 2, lazy[k]);
        apply_tag(2 * k + 1, len / 2, lazy[k]);
        lazy[k] = Tag();
    }

    void add(int l, int r, long long val, int k = 1, int ql = 1, int qr = -1) {
        if (qr == -1) qr = sz;
        if (ql >= l && qr <= r) {
            apply_tag(k, qr - ql + 1, Tag{val, 0, false});
            return;
        }
        push(k, qr - ql + 1);
        int mid = (ql + qr) / 2;
        if (l <= mid) add(l, r, val, 2 * k, ql, mid);
        if (r > mid) add(l, r, val, 2 * k + 1, mid + 1, qr);
        tree[k] = merge_node(tree[2 * k], tree[2 * k + 1]);
    }

    void assign(int l, int r, long long val, int k = 1, int ql = 1, int qr = -1) {
        if (qr == -1) qr = sz;
        if (ql >= l && qr <= r) {
            apply_tag(k, qr - ql + 1, Tag{0, val, true});
            return;
        }
        push(k, qr - ql + 1);
        int mid = (ql + qr) / 2;
        if (l <= mid) assign(l, r, val, 2 * k, ql, mid);
        if (r > mid) assign(l, r, val, 2 * k + 1, mid + 1, qr);
        tree[k] = merge_node(tree[2 * k], tree[2 * k + 1]);
    }

    Node query(int l, int r, int k = 1, int ql = 1, int qr = -1) {
        if (qr == -1) qr = sz;
        if (ql >= l && qr <= r) return tree[k];
        push(k, qr - ql + 1);
        int mid = (ql + qr) / 2;
        if (r <= mid) return query(l, r, 2 * k, ql, mid);
        if (l > mid) return query(l, r, 2 * k + 1, mid + 1, qr);
        return merge_node(query(l, r, 2 * k, ql, mid), query(l, r, 2 * k + 1, mid + 1, qr));
    }

    long long query_sum(int l, int r) { return query(l, r).sum; }
    long long query_min(int l, int r) { return query(l, r).mn; }
    long long query_max(int l, int r) { return query(l, r).mx; }
};

struct Trie {
    struct Node {
        int next[26] = {0};
        int cnt = 0;
        int pas = 0;
    };

    vector<Node> t;

    Trie() { t.emplace_back(); }

    void insert(const string& s) {
        int u = 0;
        t[u].pas++;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].next[v]) {
                t[u].next[v] = t.size();
                t.emplace_back();
            }
            u = t[u].next[v];
            t[u].pas++;
        }
        t[u].cnt++;
    }

    int count(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].next[v]) return 0;
            u = t[u].next[v];
        }
        return t[u].cnt;
    }

    int count_prefix(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!t[u].next[v]) return 0;
            u = t[u].next[v];
        }
        return t[u].pas;
    }
};

struct Trie01 {
    struct Node {
        int next[2] = {0};
    };

    vector<Node> t;

    Trie01() { t.emplace_back(); }

    void insert(int val) {
        int u = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (!t[u].next[bit]) {
                t[u].next[bit] = t.size();
                t.emplace_back();
            }
            u = t[u].next[bit];
        }
    }

    int query_max_xor(int val) {
        int u = 0, res = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (val >> i) & 1;
            int want = bit ^ 1;
            if (t[u].next[want]) {
                res |= (1 << i);
                u = t[u].next[want];
            } else {
                u = t[u].next[bit];
            }
        }
        return res;
    }
};

struct BIT {
    int n, K;
    vector<long long> tree;

    BIT(int n) : n(n) {
        K = 1 << __lg(n);
        tree.assign(n + 1, 0);
    }

    BIT(const vector<long long>& a) : n((int)a.size() - 1) {
        K = 1 << __lg(n);
        tree.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            tree[i] += a[i];
            int nj = i + (i & -i);
            if (nj <= n) tree[nj] += tree[i];
        }
    }

    void add(int i, long long val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }

    void set(int i, long long val) {
        add(i, val - get(i));
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    long long get(int i) {
        return query(i, i);
    }

    int select(long long k) {
        int idx = 0;
        for (int i = K; i > 0; i >>= 1) {
            if (idx + i <= n && tree[idx + i] < k) {
                idx += i;
                k -= tree[idx];
            }
        }
        return idx + 1;
    }
};

template <typename T = int>
struct MonoStack {
    static vector<int> next_greater(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> nxt(n + 1, n + 1);
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.back()] < a[i]) {
                nxt[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return nxt;
    }

    static vector<int> prev_greater(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> prv(n + 1, 0);
        vector<int> stk;
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.back()] < a[i]) {
                prv[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return prv;
    }

    static vector<int> next_smaller(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> nxt(n + 1, n + 1);
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                nxt[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return nxt;
    }

    static vector<int> prev_smaller(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> prv(n + 1, 0);
        vector<int> stk;
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                prv[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return prv;
    }
};

template <typename T = long long, typename Compare = less<T>>
struct SparseTable {
    int n, K;
    vector<vector<T>> st;
    Compare comp;

    SparseTable() {}

    SparseTable(const vector<T>& a) {
        n = (int)a.size() - 1;
        K = __lg(n) + 1;
        st.assign(K, vector<T>(n + 1));
        for (int i = 1; i <= n; ++i) st[0][i] = a[i];
        for (int j = 1; j < K; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                st[j][i] = comp(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]) ? st[j - 1][i] : st[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    T query(int l, int r) const {
        int j = __lg(r - l + 1);
        return comp(st[j][l], st[j][r - (1 << j) + 1]) ? st[j][l] : st[j][r - (1 << j) + 1];
    }
};

// <== Techniques ==>

int64_t count_inversions(vector<long long> a) {
    int n = (int)a.size() - 1;
    vector<long long> b = a;
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    int m = (int)b.size() - 1;
    BIT bit(m);

    long long inv_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int val = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        inv_cnt += (i - 1) - bit.query(val);
        bit.add(val, 1);
    }
    return inv_cnt;
}

template <typename T>
vector<T> Discrete(const vector<T>& a, int base = 1) {
    if (base == 0) {
        int n = (int)a.size();
        vector<T> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        vector<T> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        return res;
    } else {
        int n = (int)a.size() - 1;
        vector<T> b = a;
        sort(b.begin() + 1, b.end());
        b.erase(unique(b.begin() + 1, b.end()), b.end());

        vector<T> res(n + 1);
        for (int i = 1; i <= n; ++i) {
            res[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        }
        return res;
    }
}

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// <== Math ==>

struct BigInt {
    static constexpr int BASE = 10000;
    static constexpr int WIDTH = 4;
    vector<int> d;
    int sign = 1;

    BigInt() : d(1, 0), sign(1) {}
    BigInt(long long x) {
        sign = (x < 0) ? -1 : 1;
        x = llabs(x);
        if (x == 0) d.push_back(0);
        while (x > 0) { d.push_back(x % BASE); x /= BASE; }
        if (d.empty()) d.push_back(0);
    }
    BigInt(string s) { *this = fromString(s); }

    static BigInt fromString(string s) {
        BigInt res;
        res.d.clear();
        res.sign = 1;
        int start = 0;
        if (!s.empty() && s[0] == '-') { res.sign = -1; start = 1; }
        for (int i = (int)s.size(); i > start; i -= WIDTH) {
            int l = max(start, i - WIDTH);
            res.d.push_back(stoi(s.substr(l, i - l)));
        }
        if (res.d.empty()) res.d.push_back(0);
        res.trim();
        return res;
    }

    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
        if (d.size() == 1 && d[0] == 0) sign = 1;
    }

    bool isZero() const { return d.size() == 1 && d[0] == 0; }

    string toString() const {
        string res = (sign < 0 && !isZero()) ? "-" : "";
        res += to_string(d.back());
        for (int i = (int)d.size() - 2; i >= 0; --i) {
            string cur = to_string(d[i]);
            res += string(WIDTH - cur.size(), '0') + cur;
        }
        return res;
    }

    static int cmpAbs(const BigInt& a, const BigInt& b) {
        if (a.d.size() != b.d.size()) return a.d.size() < b.d.size() ? -1 : 1;
        for (int i = (int)a.d.size() - 1; i >= 0; --i)
            if (a.d[i] != b.d[i]) return a.d[i] < b.d[i] ? -1 : 1;
        return 0;
    }

    static vector<int> addAbs(const vector<int>& a, const vector<int>& b) {
        vector<int> res; int carry = 0;
        for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
            int cur = carry;
            if (i < a.size()) cur += a[i];
            if (i < b.size()) cur += b[i];
            res.push_back(cur % BASE);
            carry = cur / BASE;
        }
        return res;
    }
    static vector<int> subAbs(const vector<int>& a, const vector<int>& b) {
        vector<int> res = a; int borrow = 0;
        for (size_t i = 0; i < b.size() || borrow; ++i) {
            res[i] -= borrow + (i < b.size() ? b[i] : 0);
            borrow = res[i] < 0;
            if (borrow) res[i] += BASE;
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        return res;
    }

    BigInt operator-() const {
        BigInt r = *this;
        if (!r.isZero()) r.sign = -r.sign;
        return r;
    }
    BigInt operator+(const BigInt& o) const {
        BigInt res;
        if (sign == o.sign) { res.d = addAbs(d, o.d); res.sign = sign; }
        else if (cmpAbs(*this, o) >= 0) { res.d = subAbs(d, o.d); res.sign = sign; }
        else { res.d = subAbs(o.d, d); res.sign = o.sign; }
        res.trim();
        return res;
    }
    BigInt operator-(const BigInt& o) const { return *this + (-o); }

    BigInt operator*(const BigInt& o) const {
        vector<long long> tmp(d.size() + o.d.size(), 0);
        for (size_t i = 0; i < d.size(); ++i)
            for (size_t j = 0; j < o.d.size(); ++j)
                tmp[i + j] += (long long)d[i] * o.d[j];
        BigInt res; res.d.assign(tmp.size(), 0);
        long long carry = 0;
        for (size_t i = 0; i < tmp.size(); ++i) {
            long long cur = tmp[i] + carry;
            res.d[i] = cur % BASE;
            carry = cur / BASE;
        }
        while (carry) { res.d.push_back(carry % BASE); carry /= BASE; }
        res.sign = sign * o.sign;
        res.trim();
        return res;
    }

    static vector<int> mulSmall(const vector<int>& a, int x) {
        vector<int> res(a.size(), 0);
        long long carry = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            long long cur = (long long)a[i] * x + carry;
            res[i] = cur % BASE;
            carry = cur / BASE;
        }
        while (carry) { res.push_back(carry % BASE); carry /= BASE; }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        return res;
    }

    static void divModAbs(const BigInt& a, const BigInt& b, BigInt& q, BigInt& r) {
        q.d.assign(a.d.size(), 0);
        r = BigInt(0);
        for (int i = (int)a.d.size() - 1; i >= 0; --i) {
            r.d.insert(r.d.begin(), a.d[i]);
            r.trim();
            int lo = 0, hi = BASE - 1, x = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                BigInt tb; tb.d = mulSmall(b.d, mid); tb.sign = 1;
                if (cmpAbs(tb, r) <= 0) { x = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            q.d[i] = x;
            r.d = subAbs(r.d, mulSmall(b.d, x));
        }
        q.trim();
        r.trim();
    }

    BigInt operator/(const BigInt& o) const {
        BigInt q, r;
        divModAbs(*this, o, q, r);
        q.sign = q.isZero() ? 1 : sign * o.sign;
        return q;
    }
    BigInt operator%(const BigInt& o) const {
        BigInt q, r;
        divModAbs(*this, o, q, r);
        r.sign = r.isZero() ? 1 : sign;
        return r;
    }

    bool operator<(const BigInt& o) const {
        if (sign != o.sign) return sign < o.sign;
        int c = cmpAbs(*this, o);
        return sign > 0 ? c < 0 : c > 0;
    }
    bool operator==(const BigInt& o) const { return sign == o.sign && d == o.d; }
    bool operator>(const BigInt& o) const { return o < *this; }
    bool operator<=(const BigInt& o) const { return !(o < *this); }
    bool operator>=(const BigInt& o) const { return !(*this < o); }

    friend ostream& operator<<(ostream& os, const BigInt& x) { return os << x.toString(); }
    friend istream& operator>>(istream& is, BigInt& x) { string s; is >> s; x = BigInt::fromString(s); return is; }
};

struct Matrix {
    int row, col;
    long long mod;
    vector<vector<long long>> a;

    Matrix(int row, int col, long long mod) : row(row), col(col), mod(mod), a(row, vector<long long>(col, 0)) {}

    static Matrix identity(int n, long long mod) {
        Matrix res(n, n, mod);
        for (int i = 0; i < n; ++i) res.a[i][i] = 1 % mod;
        return res;
    }

    vector<long long>& operator[](int i) { return a[i]; }
    const vector<long long>& operator[](int i) const { return a[i]; }

    Matrix operator*(const Matrix& o) const {
        Matrix res(row, o.col, mod);
        for (int i = 0; i < row; ++i)
            for (int k = 0; k < col; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < o.col; ++j)
                    res.a[i][j] = (res.a[i][j] + (__int128)a[i][k] * o.a[k][j]) % mod;
            }
        return res;
    }

    Matrix power(long long exp) const {
        Matrix res = identity(row, mod);
        Matrix base = *this;
        while (exp > 0) {
            if (exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
};

long long modpow(long long base, long long exp, long long mod) {
    base %= mod;
    if (base < 0) base += mod;
    long long res = 1 % mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modinv_prime(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

long long modinv(long long a, long long mod) {
    long long x, y;
    long long g = exgcd(a, mod, x, y);
    if (g != 1) return -1;
    return ((x % mod) + mod) % mod;
}

long long GCD(long long a, long long b) { return b == 0 ? a : GCD(b, a % b); }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

struct LinearSieve {
    int n;
    vector<int> primes, min_prime, phi;

    LinearSieve(int n) : n(n), min_prime(n + 1, 0), phi(n + 1, 0) {
        phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i;
                primes.push_back(i);
                phi[i] = i - 1;
            }
            for (int p : primes) {
                if (p > min_prime[i] || (long long)i * p > n) break;
                min_prime[i * p] = p;
                if (i % p == 0) {
                    phi[i * p] = phi[i] * p;
                    break;
                } else {
                    phi[i * p] = phi[i] * (p - 1);
                }
            }
        }
    }
};

vector<pair<long long, int>> factorize(long long n) {
    vector<pair<long long, int>> res;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            res.push_back({i, cnt});
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

long long euler_phi(long long n) {
    long long res = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

bool miller_rabin(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    static const vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (long long a : bases) {
        if (n <= a) break;
        long long x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = (long long)((__int128)x * x % n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

int gauss_mod(vector<vector<long long>>& a, vector<long long>& b, vector<long long>& x, long long mod) {
    int n = (int)a.size();
    int m = (int)a[0].size();

    vector<vector<long long>> A(n, vector<long long>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = (a[i][j] % mod + mod) % mod;
        }
        A[i][m] = (b[i] % mod + mod) % mod;
    }

    vector<int> pivot_pos(m, -1);
    int row = 0;

    for (int col = 0; col < m && row < n; ++col) {
        int sel = -1;
        for (int i = row; i < n; ++i) {
            if (A[i][col] != 0) {
                sel = i;
                break;
            }
        }
        if (sel == -1) continue;

        swap(A[row], A[sel]);
        pivot_pos[col] = row;

        long long inv = modinv(A[row][col], mod);
        for (int j = col; j <= m; ++j) {
            A[row][j] = A[row][j] * inv % mod;
        }

        for (int i = 0; i < n; ++i) {
            if (i != row && A[i][col] != 0) {
                long long factor = A[i][col];
                for (int j = col; j <= m; ++j) {
                    A[i][j] = (A[i][j] - factor * A[row][j] % mod + mod) % mod;
                }
            }
        }
        row++;
    }

    x.assign(m, 0);
    for (int j = 0; j < m; ++j) {
        if (pivot_pos[j] != -1) {
            x[j] = A[pivot_pos[j]][m];
        }
    }

    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            sum = (sum + A[i][j] * x[j]) % mod;
        }
        if (sum != A[i][m]) return -1;
    }

    for (int j = 0; j < m; ++j) {
        if (pivot_pos[j] == -1) return 2;
    }

    return 1;
}

/*
<== Data Structure ==>
====================================================================
1. DSU (Disjoint Set Union)
    - DSU d(n);              : Init with size n (O(N))
    - d.find(u);             : Find root of u (O(α(N)))
    - d.same(u, v);          : Check if u and v are connected (O(α(N)))
    - d.merge(u, v);         : Union u and v (returns false if already merged) (O(α(N)))
    - d.size(u);             : Get size of component containing u (O(α(N)))
    - d.groups();            : Get all components as vector<vector<int>> (O(N))

2. SegTree (1-based, [l, r])
    - SegTree<S, op, e> seg(n);  : Init with size n (O(N))
    - SegTree<S, op, e> seg(v);  : Init with 1-based vector v (O(N))
    - seg.set(p, x);             : Update index p to value x (O(log N))
    - seg.get(p);                : Get value at index p (O(1))
    - seg.query(l, r);           : Query product in closed interval [l, r] (O(log N))
    - seg.all_prod();            : Query product of all elements [1, n] (O(1))
    - seg.max_right(l, f);       : Binary search rightmost r where f(query(l, r)) is true (O(log N))
    - seg.min_left(r, f);        : Binary search leftmost l where f(query(l, r)) is true (O(log N))

3. LazySegTree (1-based, [l, r])
    - LazySegTree seg(n);         : Init with size n (O(N))
    - LazySegTree seg(a);         : Init with 1-based vector a[1...n] (O(N))
    - seg.add(l, r, val);         : Range add [l, r] += val (O(log N))
    - seg.assign(l, r, val);      : Range assign [l, r] = val (O(log N))
    - seg.query_sum(l, r);        : Query sum in [l, r] (O(log N))
    - seg.query_min(l, r);        : Query min in [l, r] (O(log N))
    - seg.query_max(l, r);        : Query max in [l, r] (O(log N))

4. Trie (Prefix Tree)
    - Trie trie;
    - trie.insert(s);            : Insert string s (O(|S|))
    - trie.count(s);             : Count exact string s (O(|S|))
    - trie.count_prefix(s);      : Count strings starting with prefix s (O(|S|))

5. 01-Trie (Binary Trie)
    - Trie01 trie;
    - trie.insert(val);          : Insert 32-bit integer val (O(B), B=32)
    - trie.query_max_xor(val);   : Get max (val ^ x) among all inserted x (O(B), B=32)

6. BIT (1-based, Prefix Sum)
    - BIT bit(n);                : Init with size n (O(N))
    - BIT bit(a);                : Init with 1-based vector a[1...n] (O(N))
    - bit.add(i, val);           : Point add a[i] += val (O(log N))
    - bit.set(i, val);           : Point set a[i] = val (O(log N))
    - bit.get(i);                : Point query a[i] (O(log N))
    - bit.query(i);              : Query prefix sum [1, i] (O(log N))
    - bit.query(l, r);           : Query range sum in closed interval [l, r] (O(log N))
    - bit.select(k);             : Find first index with prefix sum >= k (O(log N))

7. Monotonic Stack (1-based Indexing)
    - auto nxt = MonoStack<int>::next_greater(a); : Find next index with a[j] > a[i] (O(N))
    - auto prv = MonoStack<int>::prev_greater(a); : Find prev index with a[j] > a[i] (O(N))
    - auto nxt = MonoStack<int>::next_smaller(a); : Find next index with a[j] < a[i] (O(N))
    - auto prv = MonoStack<int>::prev_smaller(a); : Find prev index with a[j] < a[i] (O(N))

8. Sparse Table (1-based, Static Range Query O(1))
    - SparseTable<int> st(a);                  : Init RMQ (O(N log N))
    - SparseTable<int, greater<int>> st_max(a); : Init Range Maximum Query (O(N log N))
    - st.query(l, r);                           : Query min/max in closed interval [l, r] (O(1))

9. PBDS
    typedef tree<
        int,                                    // Key type (or pair<int, int> for multiset)
        null_type,                              // Value type (null_type for set)
        less<int>,                              // Comparator
        rb_tree_tag,                            // Red-black tree
        tree_order_statistics_node_update       // Enables order operations
    > ordered_set;

    - ordered_set st;
    - st.insert(x);                             : Insert x (O(log N))
    - st.erase(x);                              : Erase x (O(log N))
    - st.find_by_order(k);                      : Iterator to k-th smallest element (0-based) (O(log N))
    - st.order_of_key(x);                       : Number of elements strictly smaller than x (O(log N))
====================================================================
<== Techniques ==>
====================================================================
1. Inversions (1-based)
    - count_inversions(a); : Count total inversions in 1-based vector a (O(N log N))
2. Discretization
    - compress_array(a);    : 1-based (Default), returns ranks 1 to M (O(N log N))
    - compress_array(a, 0); : 0-based, returns ranks 0 to M-1 (O(N log N))
====================================================================
<== Math ==>
====================================================================
1. BigInt (Arbitrary-Precision Integer, N = digits/WIDTH)
    - BigInt a = 123456789, b("9876543210987654321"); : Constructors (O(N))
    - cin >> a >> b; cout << a + b;                   : I/O operations supported (O(N))
    - BigInt c = a + b, d = a - b;                   : Operators (+, -) (O(N))
    - BigInt e = a * b;                              : Operator (*) (O(N^2))
    - BigInt q = a / b, r = a % b;                   : Operators (/, %) (O(N^2 log BASE))
    - if (a < b || a == b) { ... }                   : Comparison operators (O(N))

2. Matrix
    - Matrix mat(row, col, mod);        : Init row x col matrix under modulo mod (O(row * col))
    - mat[i][j] = val;                  : Access/Modify element at (i, j) (O(1))
    - Matrix I = Matrix::identity(n, mod); : Init n x n Identity Matrix (O(N^2))
    - Matrix C = A * B;                 : Matrix multiplication (O(N * M * K))
    - Matrix P = mat.power(exp);        : Matrix exponentiation (O(N^3 log(exp)))

3. Number Theory Basics
    - long long ans = modpow(base, exp, mod);  : (base^exp) % mod (O(log exp))
    - long long g = exgcd(a, b, x, y);         : Solve a*x + b*y = gcd(a, b) (O(log(min(a, b))))
    - long long inv = modinv_prime(a, p);      : Modular inverse when p is prime (O(log p))
    - long long inv = modinv(a, mod);          : General modular inverse via exgcd (O(log(min(a, mod))))
    - long long g = GCD(a, b);                 : Greatest Common Divisor (O(log(min(a, b))))
    - long long l = LCM(a, b);                 : Least Common Multiple (O(log(min(a, b))))

4. Linear Sieve
    - LinearSieve sieve(N);                    : Precomputation for [1, N] (O(N))
    - sieve.primes                             : vector<int> containing all primes <= N
    - sieve.min_prime[x]                       : Smallest prime factor of x (O(1))
    - sieve.phi[x]                             : Euler's totient value phi(x) (O(1))

5. Prime Factorization
    - auto factors = factorize(n);             : Prime factors & exponents (O(sqrt(N)))

6. Single Value Euler's Totient
    - long long p = euler_phi(n);              : Compute phi(n) directly (O(sqrt(N)))

7. Miller-Rabin Primality Test
    - bool is_p = miller_rabin(n);             : Deterministic prime test for n < 2^64 (O(k log^3 N))

8. Gaussian Elimination modulo MOD (Solves A * x = b (mod MOD))
    - int res = gauss_mod(a, b, x, mod);        : Solves system of linear equations (O(N * M * min(N, M)))
        * Returns: 
            1  : Unique solution found (stored in vector<long long> x)
            2  : Infinitely many solutions (one valid solution stored in x)
           -1  : No solution (Inconsistent system)
*/

void solve();

signed main() {
    noTLE
    int T = 1;
    // cin >> T;
    while(T--) {
        // cout << "#CASE";
        solve();
    }
}

#define int int64_t

int64_t op(int64_t a, int64_t b) {
    return a + b;
}

int64_t e() {
    return (int64_t) 0;
}

void solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++)
        cin >> a[i];   
    LazySegTree seg(a);
    int l, r;
    while(cin >> l >> r) {
        cout << seg.query_min(l, r);
        
    }
}

#undef int