// Problem : https://codeforces.com/contest/2069/problem/A
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n-=2;
        vector<int> v(n);
        for(int &i : v) cin >> i;
        bool check = 0;
        for(int i=1;i<n-1;i++) {
            if(v[i] == 0 && v[i-1] == 1 && v[i+1] == 1) {
                cout<<"NO\n";
                check = 1;
                break;
            }
        }
        if(!check) cout << "YES\n";
    }
}