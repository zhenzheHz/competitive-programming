// Problem : https://cses.fi/problemset/task/3222
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    map<int,int> cnt;
    for(int i=0;i<k;i++) {
        cnt[arr[i]] += 1;
    }
    int cur_l = 0;
    do {
        cout << cnt.size() << ' ';
        cnt[arr[cur_l+k]] += 1;
        if(--cnt[arr[cur_l]] == 0) cnt.erase(arr[cur_l]);
        cur_l++;
    } while(cur_l + k <= n);
    return 0;
}