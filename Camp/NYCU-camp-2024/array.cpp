#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int check(const vector<int> &a,int limit){
    int cnt = 0,sum = 0;
    for(const int &i : a){
        if(sum + i > limit){
            cnt++;sum = i;
        }else if(sum + i == limit){
            cnt++;sum = 0;
        }else sum += i;
    }
    if(sum)cnt++;
    return cnt;
}
int32_t main(){
    int n,m;cin>>n>>m;
    int sum = 0,mx = 0;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
        sum += i;
        mx = max(mx,i);
    }
    // for(int i=mx;i<=sum+1;i++){
    //     cerr << check(a,i) << '\n';
    // }
    int l = mx-1,r = sum+1;
    while(l+1!=r){
        int mid = (l+r)>>1;
        if(check(a,mid) <= m){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r;
}
