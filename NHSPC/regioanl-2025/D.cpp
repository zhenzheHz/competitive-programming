#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int cnt[256],frequency;
vector<int> peaks,zeros;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int L,W;
    cin >> L >> W;
    for(int i = 0; i < L*W; i++) {
        int v;
        cin >> v;
        frequency = max(frequency, ++cnt[v]);
    }
    for(int i = 0; i < 256; i++) {
        if(cnt[i] == frequency) peaks.push_back(i);
        if(cnt[i] == 0) zeros.push_back(i);
    }
    int ans = 1e18;
    for(auto &peak : peaks) {
        for(auto &zero : zeros) {
            ans = min(ans, abs(peak - zero));
        }
    }
    cout << (ans >= (int)1e18? -1 : ans);
    return 0;
}
