// Problem : https://cses.fi/problemset/task/1628
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    vector<int> frt(n/2), bck(n - n/2);
    for(int &i : frt) cin >> i;
    for(int &i : bck) cin >> i;
    vector<int> pre;
    for(int i=0;i<(1<<frt.size());i++) {
        int sum = 0;
        for(int j=0;j<frt.size();j++) {
            sum += ((i >> j) & 1) * frt[j];
        }
        pre.push_back(sum);
    }
    sort(pre.begin(),pre.end());
    int ans = 0;
    for(int i=0;i<(1<<bck.size());i++) {
        int sum = 0;
        for(int j=0;j<bck.size();j++) {
            sum += ((i >> j) & 1) * bck[j];
        }
        auto l = lower_bound(pre.begin(),pre.end(),x-sum);
        auto r = upper_bound(pre.begin(),pre.end(),x-sum);
        ans += r - l;
    }
    return cout<<ans,0;
}