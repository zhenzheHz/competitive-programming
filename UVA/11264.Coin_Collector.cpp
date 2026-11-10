// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=e591
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void withdraw(vector<int> &coins, int x,unordered_set<int> &get) {
    if(x == 0) return;
    auto found = upper_bound(coins.begin(),coins.end(),x);
    found = prev(found);
    get.insert(*found);
    withdraw(coins,x-*found,get);
}
void solve() {
    int n;
    cin >> n;
    vector<int> value;
    int prefix = 0;
    for(int i=0;i<n;i++) {
        int coin; cin >> coin;
        // cout << coin << ' ' << prefix << '\n';
        if(value.size() && prefix >= coin) {
            prefix -= value.back();
            value.pop_back();
        }
        value.push_back(coin);
        prefix += coin;
    }
    cout << value.size() << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
}