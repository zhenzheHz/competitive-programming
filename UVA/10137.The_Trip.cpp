// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=d223
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int N;
    while(cin >> N && N != 0) {
        int cost[MAXN], sum = 0;
        for(int i=0;i<N;i++) {
            double x;cin >> x;
            cost[i] = static_cast<int> (round(x*100));
            sum += cost[i];
        }
        sort(cost, cost+N);
        int average = sum / N;
        int more = sum - average * N;
        //cout << more << ' ';
        //cout << sum << ' ' <<average << '\n';
        int ans = 0;
        for(int i=0;i<N-more;i++) {
            ans += abs(cost[i] - average);
        }
        for(int i=N-more;i<N;i++) {
            ans += abs(cost[i] - average - 1);
        }
        cout << "$" << fixed << setprecision(2) << ans/100.0/2.0 << '\n';
    }
}