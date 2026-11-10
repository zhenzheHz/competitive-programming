// Problem : https://codeforces.com/problemset/problem/1725/G
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...);}
template<typename... T>
void send(T&&... args) { ((cout << args << " "), ...);cout<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

void solve(){
    int n;get(n);
    int l = 0,r = 1e18;
    function<bool(int)>check=[&](int num){
        int odd = (num+1)/2-1;
        int four = num/4;
        if(num >= 4)four-=1;
        return (odd+four<n);
    };
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m))l = m;
        else r = m;
    }
    send(r);
}

int32_t main(){
    fastio;
    int test = 1;
    //get(test);
    while(test--){
        solve();
    }
}