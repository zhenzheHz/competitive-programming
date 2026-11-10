#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int N = 1e9,R = 1e18;
vector<pair<int,int>> go(100005,{0,0});
int x=0,y=0,gx,gy,n;
bool check(int day){
    int a = day/n,b = day%n;
    int i = a*go[n].first+go[b].first;
    int j = a*go[n].second+go[b].second;
    int need = abs(gx-i) + abs(gy-j);
    return (day>=need);
}
int32_t main(){
    cin>>n;
    string s;cin>>s;
    for(int i=1;i<=n;i++){
        char dir = s[i-1];
        if(dir == 'N'){
            go[i].first = go[i-1].first;
            go[i].second = go[i-1].second + 1;
        }
        if(dir == 'S'){
            go[i].first = go[i-1].first;
            go[i].second = go[i-1].second - 1;
        }
        if(dir == 'W'){
            go[i].first = go[i-1].first - 1;
            go[i].second = go[i-1].second;
        }
        if(dir == 'E'){
            go[i].first = go[i-1].first + 1;
            go[i].second = go[i-1].second;
        }
    }
    cin >> gx >> gy;
    int l = 0,r = R+1;
    while(l+1!=r){
        int m = (l+r)>>1;
        if(check(m)){
            r = m;
        }else l = m;
    }
    if(r == R+1)cout << -1;
    else cout << r;
}
