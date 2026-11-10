// Problem : https://tioj.ck.tp.edu.tw/problems/2331
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int check(vector<int> &w, int val) {
    int ans = 0;
    for(int l=0,r=w.size()-1;l < w.size()&&l<=r;l++) {
        while(w[l] + w[r] > val && l<=r) --r;
        ans += r-l+1;
    }
    return ans;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> w(n);
    for(int &i : w) cin >> i;
    sort(w.begin(),w.end());
    k = n*(n+1)/2 - k + 1;
    int l = 2*w.front()-1, r = 2*w.back()+1;
    while(l+1!=r) {
        int m = (l+r)>>1;
        if(check(w,m) < k) l = m;
        else r = m;
    }
    if(r & 1) cout << r << '\n' << 2;
    else cout << r/2 << '\n' << 1 << '\n';
}