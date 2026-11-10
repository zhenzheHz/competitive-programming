// Problem : https://codeforces.com/contest/981/problem/C
// Tags : Constructive
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> degree(n+1,0);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        degree[a]++, degree[b]++;
    }
    int root = -1, cnt = 0, max_degree = 0;
    vector<int> leaves;
    for(int i=1;i<=n;i++) {
        cnt += degree[i] >= 3;
        if(degree[i] > max_degree) {
            max_degree = degree[i];
            root = i;
        }
    }
    for(int i=1;i<=n;i++) {
        if(degree[i] == 1 && i != root)
            leaves.push_back(i);
    }
    if(cnt > 1) return cout<<"No\n",0;
    else cout << "Yes\n";
    cout << leaves.size() << '\n';
    for(int leaf : leaves) {
        cout << root << ' ' << leaf << '\n';
    }
    return 0;
}