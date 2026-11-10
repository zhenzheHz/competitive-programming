// Problem : https://atcoder.jp/contests/abc077/tasks/arc084_b
// Tags : 0-1 BFS, Math
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int INF = 1e18;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    deque<int> q;
    vector<int> dist(k, INF);
    dist[1] = 1;
    q.push_back(1);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        int v1 = (cur * 10) % k, v2 = (cur + 1) % k;
        if(dist[cur] < dist[v1]) {
            dist[v1] = dist[cur];
            q.push_front(v1);
        }
        if(dist[cur] < dist[v2]) {
            dist[v2] = dist[cur] + 1;
            q.push_back(v2);
        }
    }
    cout << dist[0];
    return 0;
}

