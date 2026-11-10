// Author : zhenzhe
// 2026/11/05 Thu 17:09:41
#include <bits/stdc++.h>
#include <slow>
#define int int64_t
using namespace std;
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
static constexpr int MAXN = 1e5 + 5;

vector<int> f, cnt(MAXN, 0);
int cur_answer = 1;

vector<vector<int>> divs(MAXN);

struct query{
    int l, r, id, bid;
    bool operator<(const query& tmp) const { 
        return bid < tmp.bid || (bid == tmp.bid && r < tmp.r);
    }
};

void add(const int x) {
    // debug("add", x);
    for(const int d : divs[x]) {
        // debug(d);
        if(++cnt[d] >= 2) {
            chmax(cur_answer, d);
        }
    }
    // debug("check", cnt[10]);
}

void sub(const int x) {
    // debug("sub", x);
    for(const int d : divs[x]) {
        cnt[d]--;
        while(cur_answer > 1 && cnt[cur_answer] < 2) {
            cur_answer--;
        }
    }
}

void solve() {
    int n,q; cin >> n;
    f.resize(n);
    for(auto &x : f) cin >> x;
    cin >> q;
    vector<query> Q(q);
    int k = sqrt(n);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        --l, --r;
        Q[i] = {l, r, i, l / k};
    }

    sort(all(Q));

    vector<int> ans(q);

    for(int i = 1; i < MAXN; i++) {
        for(int j = i; j < MAXN; j += i) {
            divs[j].push_back(i);
        }
    }

    // cin >> q;

    int l = 0, r = -1;
    for(int i = 0; i < q; i++){
        while(l < Q[i].l) sub(f[l++]);
        while(l > Q[i].l) add(f[--l]);
        while(r < Q[i].r) add(f[++r]);
        while(r > Q[i].r) sub(f[r--]);
        ans[Q[i].id] = cur_answer;
    }

    // for(int i = 1; i <= 20; i++) {
    //     cout << cnt[i] << " \n"[i==20];
    //     debug(i, divs[i]);
    // }

    debug(ans);

    for(auto &x : ans) cout << x << '\n';
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
