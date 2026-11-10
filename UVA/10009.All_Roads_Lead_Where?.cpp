// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=d335
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve();
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}
void solve() {
    int m,q;
    cin >> m >> q;
    unordered_map<string,vector<string>> graph;
    for(int i=0;i<m;i++) {
        string a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    string ans = "", destination, get;
    function<void(string,string)> dfs = [&](string cur, string from) {
        ans.push_back(cur[0]);
        if(cur == destination) return get=ans,void();
        for(auto nxt : graph[cur]) {
            if(nxt == from) continue;
            dfs(nxt,cur);
            ans.pop_back();
        }
    };

    for(int i=0;i<q;i++) {
        string a,b;
        cin >> a >> b;
        ans = "";
        destination = b;
        dfs(a,a);
        cout << get << '\n';
    }
}