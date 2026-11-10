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
    if(mx - mn >= 2) return cout<<"Impossible\n",0;
    int fst = mp.begin()->second;
    if(!(fst&1)){
        int l=n,num=0;
        for(auto [id, get]:mp){
            if(get>fst) return cout<<"Impossible\n",0;
            if(get<fst){
                num=get;break;
            }
            l=id;
        }
        cout<<fst*l + num*(n-l);
    }

    else{
        int l=n,r=n,num=0;
        for(auto [id, get]:mp){
            
        }
    }
        
}