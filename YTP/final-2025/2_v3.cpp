#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    int idx[m], get[m];
    // int mx = -1, mn = 1e18;
    for(int i=0;i<m;i++) {
        cin >> idx[i] >> get[i];
    }
    int st[m];
    for(int i=0;i<m;i++) st[i] = i;
    sort(st,st+m,[&](const int a,const int b) {
        return idx[a] < idx[b];
    });
    int mx = *max_element(get,get+m), mn = *min_element(get,get+m);
    if(mx - mn >= 2) return cout<<"Impossible\n",0;
    bool gtr = 1, less = 1;
    for(int i=1;i<m;i++) {
        if(get[st[i-1]] >= get[st[i]]) continue;
        else {
            gtr = 0;break;
        }
    }
    for(int i=1;i<m;i++) {
        if(get[st[i-1]] <= get[st[i]]) continue;
        else {
            less = 0;break;
        }
    }
    if(!gtr && !less) return cout<<"Impossible\n",0;
    if(gtr && less) {
        int ans;
        // cout << "ck\n";
        if(get[st[0]] & 1) {
            ans = idx[st[m-1]] * get[st[0]] + (n-idx[st[m-1]]) * (get[st[0]]-1);
            // cout << idx[st[m-1]] << '\n';
        }else {
            ans = (idx[st[0]]-1) * (get[st[0]]-1) + (n-idx[st[0]]+1) * (get[st[0]]);
        }
        return cout<<ans,0;
    }
    if(gtr) {
        cout << "g\n";
        int last = idx[st[0]];
        for(int i=1;i<m;i++) {
            if(get[st[i]] != get[st[0]]) {
                last = idx[st[i]];
                break;
            }
        }
        int ans = (last-1) * (get[st[0]]-1) + (n-last+1) * (get[st[0]]);
        return cout<<ans,0;
    }
    if(less) {
        cout << "le\n";
        int last = idx[st[0]];
        for(int i=1;i<m;i++) {
            if(get[st[i]] == get[st[0]]) last = idx[st[i]];
            else break;
        }
        int ans = last * get[st[0]] + (n-last) * (get[st[0]]-1);
        return cout<<ans,0;
    }
}