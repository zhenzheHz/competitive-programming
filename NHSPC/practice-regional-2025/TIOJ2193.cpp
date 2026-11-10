// Problem : https://tioj.ck.tp.edu.tw/problems/2193
// Tags : Sort
#include <bits/stdc++.h>
using namespace std;
int ppct(int v) {
    int cnt = 0;
    while(v) cnt+=v&1, v>>=1;
    return cnt;
}
signed main() {
    using dt = pair<int,int>;
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<dt> arr(n);
    for(int i=0;i<n;i++) {
        int x;cin >> x;
        arr[i] = make_pair(x,i);
    }
    sort(arr.begin(),arr.end(),[&] (const dt a,const dt b) {
        int u = ppct(a.first), v = ppct(b.first);
        return (u==v? a.second < b.second : u < v);
    });
    for(auto &i : arr) cout << i.first << ' ';
    return 0;
}