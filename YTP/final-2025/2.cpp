#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    int mx = -1, mn = 1e18;
    for(int i=0;i<m;i++) {
        int c,x;
        cin >> c >> x;
        mp[c] = x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    if(mx - mn >= 2LL) return cout<<"Impossible\n",0;
    int fst = mp.begin()->second;
    if(fst & 1) {
        bool less = 1, greater = 1;
        int prev = fst;
        for(auto [idx,get] : mp) {
            if(get < prev) {
                less = 0;
            } 
            if(get > prev) {
                greater = 0;
            }
            prev = get;
        }
        swap(less,greater);
        if(!greater && !less) return cout<<"Impossible\n",0;
        if(greater && less) {
            // cout << "cccc1\n";
            int ans;
            int k = mp.rbegin()->first;
            int kk = mp.begin()->first;
            if(fst & 1) ans = fst * (k) + (fst - 1) * (n-k);
            else ans = (fst-1) * (kk-1) + (fst) * (n-kk+1);
            return cout<<ans,0;
        }
        int diff = -1;
        int ans;
        if(greater) {
            // cout << "cccc2\n";
            for(auto [idx,get] : mp) {
                if(get != fst) {
                    diff = idx;
                    break;
                }
            }
            ans = fst * (n-diff+1) + (fst-1) * (diff-1);
        }
        if(less) {
            for(auto [idx,get] : mp) {
                if(get == fst) {
                    diff = idx;
                }else break;
            }
            // cout << "check" << diff << "\n";
            ans = diff * fst + (n-diff) * (fst-1);
        }
        return cout<<ans,0;
    }else {
        for(auto [idx,get] : mp) {
            if(get != fst) return cout<<"Impossible\n",0;
        }
        int index = mp.begin()->first;
        int ans = (index-1) * (fst-1) + (n-index+1) * fst;
        return cout << ans,0;
    }
}