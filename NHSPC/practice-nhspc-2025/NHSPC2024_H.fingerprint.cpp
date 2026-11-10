// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2424
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e6+5, mod = 1e9+7;
int square[MAXN], sum[MAXN], cnt[MAXN], degree[MAXN];
vector<int> g[MAXN];
void dfs(int cur, int from) {
    square[cur] = sum[cur] = cnt[cur] = 0;
    if(degree[cur] == 1) cnt[cur] = 1;
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        dfs(nxt,cur);
        square[cur] += (square[nxt] + 2*sum[nxt] + cnt[nxt]);
        sum[cur] += (sum[nxt] + cnt[nxt]);
        cnt[cur] += cnt[nxt];
        square[cur] %= mod;
    }
}
void Reroot(int cur, int from) {
    for(auto nxt : g[cur]) {
        if(nxt == from) continue;
        int _square = square[cur] - (square[nxt] + 2*sum[nxt] + cnt[nxt]);
        while(_square < 0) _square += mod;
        _square %= mod;
        int _sum = sum[cur] - (sum[nxt] + cnt[nxt]);
        int _cnt = cnt[cur] - cnt[nxt];
        square[nxt] += (_square + 2*_sum + _cnt);
        sum[nxt] += (_sum + _cnt);
        cnt[nxt] += (_cnt);
        square[nxt] %= mod;
        Reroot(nxt,cur);
    }
}
int n,x,y;
int fp(int a,int b) {
    if(b == 0) return 1;
    if(b & 1) return a*fp(a,b-1)%mod;
    int h = fp(a,b>>1);
    return h * h % mod;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        degree[x]++, degree[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(n == 2) return cout << 1, 0;
    int root = 0;
    for(int i = 1; i <= n; i++) {
        if(degree[i] > 1) {
            root = i;
            break;
        }
    }
    dfs(root,root);
    Reroot(root,root);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 1) {
            ans += square[i];
            ans %= mod;
        }
    }
    ans *= fp(2,mod-2);
    ans %= mod;
    return cout<<ans,0;
}