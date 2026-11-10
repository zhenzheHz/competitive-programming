// Tags : Graph
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5;

vector<int> G[MAXN];
int color[MAXN], pa[MAXN];

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        G[i].clear();
        color[i] = pa[i] = -1;
    }
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    color[1] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto nxt : G[cur]) {
            if(color[nxt] == -1) {
                color[nxt] = color[cur] ^ 1;
                pa[nxt] = cur;
                q.push(nxt);
            }
            else if(color[cur] == color[nxt]) {
                vector<int> u,v;
                for(int tmp = cur; tmp != -1; tmp = pa[tmp]) {
                    u.push_back(tmp);
                }
                for(int tmp = nxt; tmp != -1; tmp = pa[tmp]) {
                    v.push_back(tmp);
                }
                while (u.size() > 1 && v.size() > 1 && u[u.size() - 2] == v[v.size() - 2]) {
                    u.pop_back();
                    v.pop_back();
                }
                v.pop_back();
                reverse(v.begin(), v.end());
                cout << u.size() + v.size() << '\n';
                for(auto vertex : u) cout << vertex << ' ';
                for(auto vertex : v) cout << vertex << ' ';
                return cout << '\n', void();
            }
        }
    }
    return cout << -1 << '\n', void();
}


signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}