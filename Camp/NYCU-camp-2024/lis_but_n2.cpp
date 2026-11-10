#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    int n;cin>>n;
    vector<int> arr(n),lis(n,1);
    for(int &num : arr)cin >> num;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i])
                lis[i] = max(lis[i],lis[j]+1);
        }
    }
    int ans = 0;
    for(int &length : lis){
        ans = max(ans,length);
    }
    cout << ans;
}
