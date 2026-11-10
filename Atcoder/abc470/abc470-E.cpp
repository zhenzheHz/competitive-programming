#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e5+5, mod = 998244353;

int fac[MAXN], ifac[MAXN];

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
    }
};

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    DSU dsu;
    dsu.init(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    ifac[n] = fpow(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) ifac[i - 1] = ifac[i] * i % mod;
    vector<array<int, 26>> cnt(n + 1);
    for (int i = 1; i <= n; i++) cnt[dsu.find(i)][s[i] - 'a']++;
    int ans = 1, diff = 1;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != i) continue;
        int ways = fac[dsu.sz[i]];
        for (int j = 0; j < 26; j++) {
            ways = ways * ifac[cnt[i][j]] % mod;
            if (cnt[i][j] > 1) diff = false;
        }
        ans = ans * ways % mod;
    }
    if (diff) ans = ans * fpow(2, mod - 2) % mod;
    return cout << ans << '\n', 0;
}