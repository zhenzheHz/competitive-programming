// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=d768
#include <bits/stdc++.h>
#define int int64_t
#define uncolored 0
using namespace std;
static constexpr int MAXN = 205;
const string yes = "BICOLORABLE.\n";
const string no = "NOT BICOLORABLE.\n";
void solve(int n,int m);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    while(cin >> n && n!=0) {
        cin >> m;
        solve(n,m);
    }
}
void solve(int n,int m) {
    vector<int> graph[MAXN];
    vector<int> color(MAXN, uncolored);
    for(int i=0;i<m;i++) {
        int from,to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    function<bool(int,int)> dfs = [&](int cur, int draw)->bool {
        if(color[cur]) return color[cur] == draw;
        color[cur] = draw;
        for(auto nxt : graph[cur]) {
            bool check = dfs(nxt,3 - color[cur]);
            if(!check) return false;
        }
        return true;
    };

    for(int i=0;i<n;i++) {
        if(color[i]) continue;
        bool valid = dfs(i,1);
        if(!valid) return cout<<no,void();
    }
    cout << yes;
}