// Problem : https://cses.fi/problemset/task/1084
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main(){
    fastio;
    int n,m,k;
    cin>>n>>m>>k;
    multiset<int> ms;
    vector<int> arr(m);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ms.insert(x);
    }
    for(int &i : arr)cin>>i;
    sort(all(arr));
    int ans = 0;
    for(int i=0;i<m;i++){
        auto find = ms.lower_bound(arr[i]-k);
        if(find == ms.end())continue;
        //cerr << arr[i] << ' ' << *find << '\n';
        if(*find <= arr[i]+k){
            ++ans;
            ms.erase(find);
        }
    }
    cout << ans;
}