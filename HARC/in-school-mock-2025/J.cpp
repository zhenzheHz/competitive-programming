#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,k;
vector<int> a;
bool check(int s) {
    int cnt = 0, tmp = 0;
    for(int i=0;i<n;i++) {
        if(tmp + a[i] <= s) tmp += a[i];
        else cnt += 1, tmp = a[i];
    }
    if(tmp) cnt += 1;
    return cnt<=k;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int mx = -1, sum = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int L;cin >> L;
        sum += L;
        mx = max(mx,L);
        a.push_back(L);
    }
    // a.push_back((int)1e18);
    int l = mx-1, r = sum+1;
    while(l+1!=r) {
        int mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}