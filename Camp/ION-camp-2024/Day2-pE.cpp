#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
int k;
struct qqq{
    int l,r,i;
    bool operator<(const qqq&cmp)const{
        return ((l/k == cmp.l/k)? r < cmp.r : l/k < cmp.l/k );
    }
};
vector<int> mp(2e5+5,0);
vector<int> v,arr(2e5+5);
void add(int index,int &sum){
    if(mp[arr[index]] == 0)sum+=1;
    mp[arr[index]]++;
}
void sub(int index,int &sum){
    if(--mp[arr[index]] == 0)sum-=1;
}
int32_t main(){
    fastio;
    int n,q;
    cin>>n>>q;
    k = sqrt(n);
    k += 1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    vector<qqq> query;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        query.push_back({l,r,i});
    }
    sort(all(v));
    sort(all(query));
    v.resize(unique(all(v))-v.begin());
    for(int i=0;i<n;i++){
        arr[i] = lower_bound(all(v),arr[i])-v.begin();
    }
    vector<int> ans(q);
    int L=0,R=0,cur=0;
    add(0,cur);
    for(int i=0;i<q;i++){
        while(R < query[i].r-1)add(++R,cur);
        while(R > query[i].r-1)sub(R--,cur);
        while(L < query[i].l-1)sub(L++,cur);
        while(L > query[i].l-1)add(--L,cur);
        //cerr << L << ' ' << R << '\n';
        ans[query[i].i] = cur;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}
