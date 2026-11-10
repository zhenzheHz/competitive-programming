#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    int n;cin>>n;
    if(n == 1){cout << "Composite";return 0;}
    for(int i=2;i<n;i++){
        if(n%i == 0){
            cout << "Composite";
            return 0;
        }
    }
    cout << "Prime";
}
