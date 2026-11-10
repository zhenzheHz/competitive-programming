// Problem : https://codeforces.com/problemset/problem/439/D
// Tags : Ternary Search
#include <bits/stdc++.h>   
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    vector<int> a(sizeA), b(sizeB);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l = 0, r = 1e9+1, ml, mr;
    function<int(int)> cal = [&](int mini) {
        int total = 0;
        for(int &x : a) {
            if(x < mini) total += mini-x;
        }
        for(int &x : b) {
            if(x > mini) total += x - mini;
        }
        return total;
    };
    while(r - l >= 3) {
        ml = l + (r-l)/3;
        mr = r - (r-l)/3;
        if(cal(ml) <= cal(mr)) r = mr;
        else l = ml;
    }
    int ans = LLONG_MAX;
    for(int i=l;i<=r;i++) ans = min(ans, cal(i));
    return cout<<ans,0;
}
