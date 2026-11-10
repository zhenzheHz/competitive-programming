#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...)}
template<typename... T>
void send(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

int32_t main(){
    //syntax = sort(),but stable sort
    vector<int> arr = {5,3,4,1,2};
    stable_sort(all(arr));
    for(int &i : arr){
        send(i);
    }
}