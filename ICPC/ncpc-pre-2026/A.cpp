#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;cin>>N;
    while(N--){
        int n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int numin = 0,numde = 0;
        int ansin = 0, ansde = 0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                if(numin>=k-1) ansin++;numin = 0;
                if(numde>=k-1) ansde++;numde = 0; 
            }
            else if(arr[i]<arr[i-1]){
                if(numin>=k-1) ansin++;
                numin = 0;
                numde++;
            }
            else if(arr[i]>arr[i-1]){
                if(numde>=k-1) ansde++;
                numde = 0;
                numin++;
            }
        }
        if(numin>=k-1) ansin++;
        if(numde>=k-1) ansde++;
        cout<<ansin<<" "<<ansde<<'\n';
    }
    
}