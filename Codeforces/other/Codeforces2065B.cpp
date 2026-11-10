// Problem : https://codeforces.com/contest/2065/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<char> v;
        bool check = 0;
        for(auto c : s) {
            if(v.size() && c == v.back()) {
                cout<<1<<'\n';
                check = 1;
                break;
            }else {
                v.push_back(c);
            }
        }
        if(check) continue;
        cout << v.size() << '\n';
    }
}