#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> win(n, vector<int>());

    for(int x=0;x<n; x++){
        for(int y=0; y<n/2; y++){
            win[(x+y+1)%n].push_back(x);
        }
    }
    while(m--){
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        vector<int> v(n);
        for(auto b : a){
            for(auto t : win[b-1]){
                v[t]++;
            }
        }
        bool yes=1;
        for(int x=0; x<n; x++){
            if(v[x]>=3){
                cout << x+1 << endl;
                yes=0;
                break;
            }
        }
        if(yes) cout << "-1\n";
    }
}