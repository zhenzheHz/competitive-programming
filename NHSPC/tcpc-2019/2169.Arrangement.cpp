// Author : Zhenzhe
// Time : 2024 / 11 / 19
// Info : 2019 北市賽 pA
// Tags : Josephus Problem(數論)
// Problem : https://tioj.ck.tp.edu.tw/problems/2169
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int josephus(int n, int m) {
    if(n == 1) return 0;
    return (josephus(n-1,m) + m) % n;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k,m=0;
    cin >> n >> k;
    for(m=2;m<=(int)3e4;m++) {
        int tmp = josephus(n,m);
        if(tmp+1 == k)
            return cout<<m,0;
    }
    cout << "0\n";
}