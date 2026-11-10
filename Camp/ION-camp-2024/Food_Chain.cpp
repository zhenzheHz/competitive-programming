// Problem : https://tioj.ck.tp.edu.tw/problems/1448
#pragma GCC optimize("O2")
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
class Disjoint_set_union{
    private:
        vector<int> parent;
    public:
        explicit Disjoint_set_union(int n){
            parent.resize(3*n+1);
            for(int i=1;i<=3*n+1;i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(x == parent[x])return x;
            return parent[x] = find(parent[x]);
        }
        void merge(int sp,int sub){
            parent[find(sub)] = find(sp);
        }
};
int32_t main(){
    fastio;
    int n,q;
    cin>>n>>q;
    Disjoint_set_union dsu(n);
    int ans = 0;
    while(q--){
        int op;cin>>op;
        int x,y;cin>>x>>y;
        if(x>n||y>n){++ans;continue;}
        if(op==1){
            if(dsu.find(x) == dsu.find(y))continue;
            if(dsu.find(x+n) == dsu.find(y) || dsu.find(x+2*n) == dsu.find(y)){
                ++ans;
            }else{
                dsu.merge(x,y);
                dsu.merge(x+n,y+n);
                dsu.merge(x+2*n,y+2*n);
            }
        }else{
            if(dsu.find(x) == dsu.find(y) || dsu.find(y+n) == dsu.find(x)){
                ++ans;
            }else{
                dsu.merge(x+n,y);
                dsu.merge(x,y+2*n);
                dsu.merge(x+2*n,y+n);
            }
        }
    }
    cout << ans;
}
//op : 1 eat 2
// fake : 2 eat 1
// 1,2 be eaten
// 2,1 eaten
// 1 be eaten,2 eaten

//op : 2 eat 3
// 1,2be eaten
// 2,3 be eaten,1 be eaten
// 1 be eaten
// 2 eaten,3
// 3 eaten