#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,k;
vector<int> ans;

void dfs(int idx, int sum) {
    if(idx == n) {
        if((k-sum) % n == 0) {
            ans[n-1] = (k-sum)/n;
            for(auto x : ans) cout << x << ' ';
            cout << '\n';
        }
        return;
    }
    for(int cur = 0; cur <= (k-sum)/idx; cur++) {
        ans[idx-1] = cur;
        dfs(idx+1, sum + cur * idx);
    }
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k;
    ans.resize(n);
    dfs(1,0);
    return 0;
}