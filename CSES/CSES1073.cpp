// Problem : https://cses.fi/problemset/task/1073
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n), id(n), st(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        id[i] = i;
        st[i] = i;
    }
    stable_sort(id.begin(), id.end(), [&](auto a, auto b) {
        if(arr[a] == arr[b]) return st[a] < st[b];
        else return arr[a] < arr[b];
    });
    set<int> lst;
    for(int i=0;i<n;i++) {
        auto f = lst.upper_bound(id[i]);
        if(f == lst.end()) lst.insert(id[i]);
        else {
            lst.erase(f);
            lst.insert(id[i]);
        }
    }
    cout << lst.size() << '\n';
    return 0;
}