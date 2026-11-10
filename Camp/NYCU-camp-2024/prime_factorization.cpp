#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    int number;
    cin >> number;
    for(int i=2;i<=number;i++){
        if(!number)break;
        int cnt = 0;
        while(number&&number %i == 0){
            number /= i;
            cnt += 1;
        }
        if(cnt)cout << i << ' ' << cnt << '\n';
    }
}
