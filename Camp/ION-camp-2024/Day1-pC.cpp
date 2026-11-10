#include <bits/stdc++.h>
#define int int64_t
#define fastio ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
template<typename... T>
void send(T&&... args){((cout << args << ' '),...);cout << '\n';}
int32_t main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    unordered_map<int,vector<pair<int,int>>> sum;
    for(int &i : arr)cin>>i;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            int plus = arr[i] + arr[j];
            if(plus > x)continue;
            if(sum.find(x-plus) != sum.end()){
                for(auto &[x,y] : sum[x-plus]){
                    if(x!=i && x!=j && y!=i && y!=j){
                        send(x+1,y+1,i+1,j+1);
                        return 0;
                    }
                }
            }
            sum[plus].push_back({i,j});
        }
    }
    cout << -1;
}