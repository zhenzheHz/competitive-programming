// Problem : https://cses.fi/problemset/task/2162
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int int64_t
using namespace std;
using namespace __gnu_pbds;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbt;
    for (int i = 1; i <= n; i++) rbt.insert(i);
    int idx = 0;
    while (!rbt.empty()) {
        idx = (idx + k) % rbt.size();
        auto it = rbt.find_by_order(idx);
        cout << *it << " ";
        rbt.erase(it);
    }
    cout << "\n";
}
