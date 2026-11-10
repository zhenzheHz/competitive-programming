#include<bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(){
    int n,b;cin>>n>>b;
    vector<int> arr(n);
    for(int i=0;i<n-1;i++) cin>>arr[i];
    int de = 1;
    for(int i=0;i < n-1;i++){
        if(arr[i] >= 0){
            b+=arr[i];
            de = 0;
        }
        //cout<<b<<'\n';
    } 
    if(!de) cout<<b;
    else{
        int ans = 1;
        for(int i=0;i<n-1;i++){
            if(arr[i] >= 0) continue;
            if(ans==1) ans = arr[i];
            else ans = max(ans,arr[i]);
        }
        b = b+ans;
        if(b<0) cout<<-1;
        else cout<<b;
    }
}

