#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int check(vector<int>&f, int n, int k) {
    int l, r;l = 0, r = 1;
    int ans = 0;
    while(1) {
        if(l >= n || r >= n + 1) break;

        while(r != n && f[r] > f[r - 1]) r++;

        if(r - l >= k) ans++;
        l = r;
        r = l + 1;
    }

    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;cin>>N;
    while(N--) {
        int n, k;cin>>n>>k;
        vector<int>f(n);

        for(int &i : f) cin>>i;

        cout<<check(f, n, k)<<" ";

        reverse(f.begin(), f.end());

        cout<<check(f, n, k)<<"\n";
    }
    return 0;
}