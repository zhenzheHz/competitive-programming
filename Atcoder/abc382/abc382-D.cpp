// Problem : https://atcoder.jp/contests/abc382/tasks/abc382_d
// Tags : Recursion
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,m;
vector<int> construct;
vector<vector<int>> ans;
void dfs(int start, int index) {
    if(index == n+1) return ans.push_back(construct),void();
    if(start + (n - index) * 10 > m) return;
    for(int i=start;i<=m;i++) construct[index-1] = i,dfs(i+10, index+1);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    construct.resize(n);
    dfs(1,1);
    // sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++) {
        for(int &x : ans[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}