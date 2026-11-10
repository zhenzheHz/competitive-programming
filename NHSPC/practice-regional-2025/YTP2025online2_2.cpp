// Author : Zhenzhe
// Problem : https://oj.ntucpc.org/problems/952
#include <bits/stdc++.h>
#define int int64_t
#define id first
#define candy second
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> st(m);
    for(auto &[a,b] : st) cin >> a >> b;
    sort(st.begin(), st.end());
    if(st[0].candy & 1) {
        bool stay = 1, inc = 1, dec = 1, valid = 1;
        for(int i = 1; i < m; i++) {
            // cout << st[i-1].candy << ' ' << st[i].candy << '\n';
            if(abs(st[i-1].candy - st[i].candy) > 1) valid = 0;
            if(st[i-1].candy < st[i].candy) dec = 0;
            if(st[i-1].candy > st[i].candy) inc = 0;
            if(st[i-1].candy != st[i].candy) stay = 0;
        }
        // cout << valid << stay << dec << inc << '\n';
        if(!valid || (!stay && !dec && !inc)) return cout<<"Impossible\n",0;
        int ans;
        if(stay) ans = st.rbegin()->id * st.rbegin()->candy + (n-st.rbegin()->id) * (st.rbegin()->candy - 1);
        else {
            int critical = -1;
            for(int i = 1; i < m; i++) {
                if(st[i-1].candy != st[i].candy) {
                    critical = (inc? st[i].id - 1 : st[i-1].id);
                }
            }
            int ot = (inc? 1 : -1);
            ans = (st.begin()->candy) * critical + (st.begin()->candy + ot) * (n - critical);
        }
        return cout << ans, 0;
    }
    else {
        bool valid = 1;
        for(int i = 1; i < m; i++) {
            if(st[i-1].candy != st[i].candy) valid = 0; 
        }
        if(!valid) return cout<<"Impossible\n",0;
        int ans = (st.begin()->id-1) * (st.begin()->candy-1) + (n - st.begin()->id + 1) * (st.begin()->candy);
        return cout<<ans,0;
    }
    return 0;
}