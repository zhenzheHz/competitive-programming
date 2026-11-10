#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int, int>>f(n);

    for(auto &i : f) cin>>i.first>>i.second;
    sort(f.begin(), f.end());

    int ans = 0;
    int now = 0;
    int mmax = 0;
    for(auto &[l, r] : f) {
        if(l > mmax) {
            now = 0;
        }
        mmax = max(mmax, r);
        now++;
        ans = max(ans, now);
    }

    cout<<ans;
    return 0;
}