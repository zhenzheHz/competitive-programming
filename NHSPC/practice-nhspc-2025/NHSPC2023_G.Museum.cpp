// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2373
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    stable_sort(c.begin(), c.end(), [&](const pair<int,int> &a,const pair<int,int> &b) {
        return (a.first == b.first? a.second < b.second : a.first > b.first);
    });
    sort(c.begin(), c.begin()+k, [&](const pair<int,int> &a,const pair<int,int> &b) {
        return a.second < b.second;
    });
    int ans = 0;
    for(int i = 0; i < k; i++) {
        ans += abs(c[i].second - i);
    }
    return cout<<ans,0;
}