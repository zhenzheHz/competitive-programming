#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int mod = 998244353;
static constexpr int g = 3;

int fp(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return fp(a, mod - 2);
}

void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = fp(g, (mod - 1) / len);
        if (invert) wlen = inv(wlen);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = a[i + j + len / 2] * w % mod;
                a[i + j] = (u + v >= mod ? u + v - mod : u + v);
                a[i + j + len / 2] = (u - v < 0 ? u - v + mod : u - v);
                w = w * wlen % mod;
            }
        }
    }

    if (invert) {
        int n_inv = inv(n);
        for (int& x : a) x = x * n_inv % mod;
    }
}

using Int = vector<int>;

Int mul(const Int& a, const Int& b) {
    if (a.empty() || b.empty()) return {};
    if (min(a.size(), b.size()) <= 32) {
        Int c(a.size() + b.size() - 1, 0);
        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b.size(); j++) {
                c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
            }
        }
        return c;
    }
    int n = 1;
    while (n < a.size() + b.size() - 1) n <<= 1;

    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n, 0);
    fb.resize(n, 0);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] = fa[i] * fb[i] % mod;
    }
    ntt(fa, true);

    fa.resize(a.size() + b.size() - 1);
    return fa;
}

Int solve(int l, int r) {
    if (l > r) return {1};
    if (l == r) return {l, 1};
    int mid = (l + r) >> 1;
    return mul(solve(l, mid), solve(mid + 1, r));
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    
    if (k < n || k > 2 * n - 1) return cout << 0 << '\n', 0;
    
    int r = 2 * n - k;
    Int f = solve(1, n - 1);
    int ans = f[r - 1];
    
    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac = fac * i % mod;
    }
    
    ans = ans * inv(fac) % mod;
    cout << ans << '\n';
    return 0;
}