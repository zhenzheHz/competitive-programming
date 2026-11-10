// Problem : https://atcoder.jp/contests/abc389/tasks/abc389_c
// Tags : Prefix Sum
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, tmp = 0;
    cin >> n;
    deque<int> q;
    while(n--) {
        int op,x;
        cin >> op;
        if(op == 1) {
            cin >> x;
            if(q.size()) x += q.back();
            q.push_back(x);
        } 
        else if(op == 2) {
            tmp += q.front() - tmp;
            q.pop_front();
        } else {
            cin >> x;
            int ans;
            if(x > 1) ans = q[x-2] - tmp;
            else ans = 0;
            cout << ans << '\n';
        }
        // for(int &i :q) cout << i << ' ';
        // cout << '\n';
    }
}