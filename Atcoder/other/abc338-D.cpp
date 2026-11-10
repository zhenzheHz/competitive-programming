// Problem : https://atcoder.jp/contests/abc388/tasks/abc388_d
// Tags : Prefix Sum, Difference
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,get = 0;
    cin >> n;
    vector<int> arr(n+1),prefix(n+1,0);
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n;i++) {
        get += prefix[i];
        arr[i] += get;
        get += 1;
        if(arr[i] >= n-i) arr[i] -= n-i;
        else prefix[i+arr[i]+1] -= 1,arr[i] = 0;
    }
    for(int i=1;i<=n;i++) cout << arr[i] << " \n"[i==n];
    return 0;
}
