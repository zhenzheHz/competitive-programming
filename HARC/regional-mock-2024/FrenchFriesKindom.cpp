#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int recursion(vector<int> &a,int l,int r){
    if(r - l<1)return 0; 
    if(r-l==1){
        if(a[l] > a[r])return 1;
        else return 0;
    }
    int m = (l+r)>>1,cnt = 0;
    vector<int> l_arr(a.begin()+l,a.begin()+m+1);
    sort(l_arr.begin(),l_arr.end());
    for(int i=m+1;i<=r;i++){
        auto index = upper_bound(l_arr.begin(),l_arr.end(),a[i]) - l_arr.begin();
        if(index<0||index>=l_arr.size())continue;
        cnt += (l_arr.size() - index);
    }
    return recursion(a,l,m) + recursion(a,m+1,r) + cnt;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<int> arr(n),index(n+100);
    vector<vector<int>> div(k);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        index[arr[i]] = i;
        div[arr[i]%k].push_back(arr[i]);
    }
    vector<int> nw,deal(n);
    for(int i=0;i<k;i++) {
        for(int j=0;j<div[i].size();j++) {
            nw.push_back(div[i][j]);
        }
    }
    //for(int i : nw) cout << i << ' ';
    for(int i=0;i<n;i++) {
        deal[i] = index[nw[i]];
        //cout << deal[i] << ' ';
    }
    cout << recursion(deal,0,n-1) << '\n';
}