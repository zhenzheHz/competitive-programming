// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2023 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2373
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k,c[MAXN],deal[MAXN];
    multiset<int> ms,idx;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        ms.insert(c[i]);
    }
    while(ms.size() > k) ms.erase(ms.begin());
    for(int i=0;i<n;i++) {
        if(ms.find(c[i]) != ms.end()) {
            deal[i] = 1;
            ms.erase(ms.find(c[i]));
            idx.insert(i);
        }else c[i] = 0;
    }
    int ans = 0;
    for(int index = 0;index < k;index++) {
        if(idx.find(index) == idx.end()) {
            int k = *idx.rbegin();
            idx.erase(prev(idx.end()));
            ans += abs(k-index);
        }
    }
    cout << ans << '\n';
}