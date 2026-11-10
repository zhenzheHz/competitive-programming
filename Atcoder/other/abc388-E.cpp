// Problem : https://atcoder.jp/contests/abc388/tasks/abc388_e
// Tags : Binary Search for Answer
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> height(n);
    for(int &i : height) cin >> i;
    function<bool(int)> check = [&](int qty) {
        for(int i=0;i<qty;i++) {
            if(height[i] * 2 > height[n-qty+i])
                return false;
        }
        return true;
    };
    int l = -1, r = n/2+1;
    while(l+1!=r) {
        int m = (l+r) >> 1;
        if(check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}