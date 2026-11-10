// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2020 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2227
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2505;
int n;
vector<int> fr[MAXN];
int Cn2(int k) {
    return k * (k-1) / 2;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) {
        int k; cin >> k;
        for(int j=0;j<k;j++) {
            int s;
            cin >> s;
            fr[i+1].push_back(s);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        ans += Cn2(fr[i].size());
        // cout << "i = " << i << ", " << Cn2(fr[i].size()) << '\n';
    }
    cout << ans << '\n';
}