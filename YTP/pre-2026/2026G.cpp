#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MOD = 998244353;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,d;
    cin >> n >> d;
    int ans = 0;
    int s[n];
    for(int i = 0 ; i < n; i++) {
        int x,y;
        cin >> x >> y;
        s[i] = x + y;
    }
    unordered_map<int,int> cnt;
    for(int i = 0 ; i < n; i++) cnt[s[i]]++;
    for(auto &[v,c] : cnt) {
        if(cnt.count(v+d)) ans += c * cnt[v+d];
    }
    return cout<<ans,0;
}