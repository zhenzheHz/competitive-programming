#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,q;
vector<int> ans;
void dfs(int cur) {
    if((cur<<1) <= n) {
        dfs(cur<<1);
        ans[cur] += ans[cur<<1];
    }
    if((cur<<1|1) <= n) {
        dfs(cur<<1|1);
        ans[cur] += ans[cur<<1|1];
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> q;
    ans.resize(n+1);
    for(int i=1;i<=n;i++) {
        cin >> ans[i];
    }
    dfs(1);
    while(q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}