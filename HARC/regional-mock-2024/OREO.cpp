#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using OREO = vector<vector<char>>;
OREO rotate90(OREO a) {
    OREO c;
    c.resize(6,vector<char>(6));
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            c[j][6-i-1]  = a[i][j];
        }
    }
    return c;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    OREO a,b;
    a.resize(6,vector<char> (6));
    b.resize(6,vector<char> (6));
    for(int i=0;i<6;i++) for(int j=0;j<6;j++) cin >> a[i][j];
    for(int i=0;i<6;i++) for(int j=5;j>=0;j--) cin >> b[i][j];
    //for(int i=0;i<6;i++) for(int j=0;j<6;j++) cout << b[i][j] << " \n"[j==5];
    for(int x=0;x<4;x++) {
        bool check = 1;
        for(int i=0;i<6;i++)for(int j=0;j<6;j++) {
            if(a[i][j] + b[i][j] != a[0][0]+b[0][0]) {
                check = 0;
                break;
            }
        }
        if(check) return cout<<"Yes\n",0;
        b = rotate90(b);
    }
    cout << "No\n";
}