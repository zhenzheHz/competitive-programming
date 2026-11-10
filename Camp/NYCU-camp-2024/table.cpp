#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n;
int count_less(int number){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += min(number/i,n);
    }
    return cnt;
}
int32_t main(){
    cin>>n;
    int median = (n*n+1)>>1;
    int l = 0,r = n*n+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(count_less(m)<median)l = m;
        else r = m;
    }
    cout << r;
}
