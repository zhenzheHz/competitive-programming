// Problem : https://cses.fi/problemset/task/1090
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;

int32_t main(){
    int n,x;
    cin>>n>>x;
    multiset<int> ms;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ms.insert(x);
    }
    int sum = 0;
    while(!ms.empty()){
        auto tmp = ms.begin();
        sum += 1;
        ms.erase(tmp);
        if(*tmp == x)continue;
        auto find = ms.lower_bound(x - *tmp);
        if(*find != x-*tmp){
            //cerr << x-sum << ' ' <<*find << '\n';
            if(find == ms.begin())continue;
            find = prev(find);
            ms.erase(find);
        }else{
            ms.erase(find);
        }
    }
    cout << sum;
}