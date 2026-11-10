// Author : Zhenzhe
// Time : 2024 / 11 / 02
// Problem : https://zerojudge.tw/ShowProblem?problemid=e565
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int gcd(int a,int b) {
    if(b == 0) return a;
    if(a == 0) return b;
    return gcd(b,a%b);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line, num;
    while(getline(cin,line)) {
        if(line == "0") break;
        stringstream seq;
        vector<int> Array,diff;
        seq << line;
        while(seq >> num) {
            if(num == "0") break;
            Array.push_back(stoi(num));
        }
        for(int i=0;i<Array.size()-1;i++) {
            diff.push_back(abs(Array[i+1] - Array[i]));
        }
        int ans = diff[0];
        for(int i=0;i<diff.size();i++) {
            ans = gcd(ans,diff[i]);
        }
        cout << ans << '\n';
    }
}