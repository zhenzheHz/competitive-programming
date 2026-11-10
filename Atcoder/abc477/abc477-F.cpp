// Author : zhenzhe
// 2026/09/26 Sat 21:04:33
#include <bits/stdc++.h>
#include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

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

struct BIT2 {
    int n;
    BIT bit1, bit2;

    BIT2(int n) : n(n), bit1(n), bit2(n) {}

    void BIT2_add(int l, int r, long long val) {
        bit1.add(l, val);
        bit1.add(r + 1, -val);
        bit2.add(l, val * (l - 1));
        bit2.add(r + 1, -val * r);
    }

    long long prefix_query(int i) {
        return bit1.query(i) * i - bit2.query(i);
    }

    long long BIT2_query(int l, int r) {
        if (l > r) return 0;
        return prefix_query(r) - prefix_query(l - 1);
    }
};

struct Query {
    int row;
    int c,d;
    int sign;
    int idx;
};

void solve() {
    int N,M,Q;
    cin >> N >> M >> Q;

    vector<pair<int,int>> rows(N+1);
    #define x first
    #define y second

    for(int i = 1; i <= N; i++) cin >> rows[i].x >> rows[i].y;


    vector<vector<Query>> events(N+1);
    for (int i = 0; i < Q; ++i) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        events[B].push_back({B, C, D, 1, i});
        if (A - 1 > 0) {
            events[A-1].push_back({A-1, C, D, -1, i});
        }
    }

    vector<int> ans(Q, 0);
    BIT2 bit(M);

    for (int r = 1; r <= N; ++r) {
        bit.BIT2_add(rows[r].first, rows[r].second, 1);
        for (const auto& q : events[r]) {
            int res = bit.BIT2_query(q.c, q.d);
            ans[q.idx] += q.sign * res;
            debug(res);
        }
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}