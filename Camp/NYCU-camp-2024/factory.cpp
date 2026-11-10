#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int R = 2e18;
int n,m;
vector<int> times;
bool check(int T){
    int cnt = 0;
    for(int &tm : times){
        cnt += T/tm;
        if (cnt >= m) return true;
    }
    return (cnt>=m);
}
int32_t main(){
    cin>>n>>m;
    times.resize(n);
    for(int &x : times){
        cin >> x;
    }
    int l=0,r=R+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m))r = m;
        else l = m;
    }
    cout << r;
}
