// Problem : https://codeforces.com/contest/727/problem/A
// Tags : Brute Force
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int64_t a,b;
bool found = 0;
vector<int> path;
void dfs(int now) {
    if(found || now > b) return;
    path.push_back(now);
    if(now == b) {
        cout << "YES\n" << path.size() << '\n';
        for(int x : path) cout << x << ' ';
        return found = 1, void();
    }
    dfs(now*10+1);
    dfs(now*2);
    path.pop_back();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> a >> b;
    dfs(a);
    if(!found) cout << "NO";
}