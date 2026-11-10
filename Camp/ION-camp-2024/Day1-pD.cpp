#include <bits/stdc++.h>
#define int int64_t
#define fastio ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
int n,k;
int check(vector<int>&arr,int x){
    int cnt = 0;
    int save = 0;
    for(int i=0;i<n;i++){
        if(save + arr[i] > x && save){
            save = arr[i];
            cnt += 1;
        }else save += arr[i];
    }
    if(save)cnt++;
    return cnt;
}
int32_t main(){
    fastio;
    cin >> n >> k;
    vector<int> arr(n);
    int mx = -1,sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mx = max(arr[i],mx);
        sum += arr[i];
    }
    int l = mx-1,r = sum+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(arr,m)<=k)r = m;
        else l = m;
    }
    cout << r;
}
