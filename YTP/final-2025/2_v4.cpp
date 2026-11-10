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
        int rec=0, recg= 0, odd=0;
        for(auto [idx,get] : mp) {
            if(!(get & 1)){
                if(rec==0){
                    rec = idx;
                    recg = get;
                }

            }
            else{
                if(rec != 0){
                    return cout<<"Impossible\n",0;
                }
                odd = idx;
            }
        }
        if(fst > recg){
            return cout<< n*fst - odd + 1, 0;
        }
        else{
            return cout << n*recg - rec + 1, 0;
        }
        
    }else {
        for(auto [idx,get] : mp) {
            if(get != fst) return cout<<"Impossible\n",0;
        }
        int index = mp.begin()->first;
        int ans = fst*n - index + 1;//(index-1) * (fst-1) + (n-index+1) * fst;
        return cout << ans,0;
    }
}