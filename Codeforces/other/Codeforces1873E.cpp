// Problem : https://codeforces.com/problemset/problem/1873/E
#include <bits/stdc++.h>
using namespace std;

int64_t check(const vector<int> &col, int64_t h) {
    int64_t sum = 0;
    for(int x : col) {
        if (h > x) {
            sum += (h - x);
        }
    }
    return sum;
}

void solve() {
    int n;
    int64_t x;
    cin >> n >> x;
    
    vector<int> a(n);
    for(int &val : a) cin >> val;
    
    int64_t l = 0, r = 2e9 + 5;
    while(l + 1 != r) {
        int64_t mid = l + (r - l) / 2;
        if(check(a, mid) > x) r = mid;
        else l = mid;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}