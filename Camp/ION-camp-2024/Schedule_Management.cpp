// Problem : https://codeforces.com/problemset/problem/1701/C
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
    int n,m;
    get(n,m);
    vector<int> cnt(n+1,0);
    for(int i=0;i<m;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    function<bool(int)>check=[&](int times){
        int can_do = 0;
        for(int i=1;i<=n;i++){
            can_do += min(times,cnt[i]);
            if(times > cnt[i])can_do += (times-cnt[i])>>1;
        }
        return (can_do >= m);
    };
    int l = 0,r = 2*m+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m))r = m;
        else l = m;
    }
    send(r);
}

int32_t main(){
    fastio;
    int test = 1;
    get(test);
    while(test--){
        solve();
    }
}