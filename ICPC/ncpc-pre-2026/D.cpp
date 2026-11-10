#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, qq;cin>>n>>m>>k>>qq;
    vector<vector<array<int, 3>>>f(n + 10);
    for(int i = 0;i<m;i++) {
        int a, b, c, d;cin>>a>>b>>c>>d;
        a--;b--;
        f.at(a).push_back({b, c, d});
        f.at(b).push_back({a, c, d});
    }

    vector<vector<map<int, int>>>v(n + 10, vector<map<int, int>>(k + 10));
    for(int i = 0;i<qq;i++) {
        int a, b, c, d;cin>>a>>b>>c>>d;
        a--;
        v.at(a).at(b).insert({c, d});
    }

    vector<vector<bool>>mark(n + 10, vector<bool>(k + 10));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>q;
    
    for(int i = 0;i<k;i++) q.push({0, 0, i});

    while(!q.empty()) {
        auto now = q.top();q.pop();

        int l = now[0];
        int d = now[1];
        int t = now[2];

        if(d == n - 1) return cout<<l, 0;

        if(mark.at(d).at(t)) continue;
        mark.at(d).at(t) = 1;

        for(auto [nd, nt, nv] : f.at(d)) {
            auto found = v.at(d).at(t).find(nt);
            if(t != nt && found == v.at(d).at(t).end()) continue;

            if(t != nt) nv += found -> second;

            q.push({l + nv, nd, nt});
        }
    }

    cout<<-1;
    return 0;
}