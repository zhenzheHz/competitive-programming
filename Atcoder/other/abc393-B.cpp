// Problem : https://atcoder.jp/contests/abc393/tasks/abc393_b
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string s, tmp = "";
    cin >> s;
    int n = s.size(), ans = 0;
    for(int i=0;i<n;i++) {
        tmp = "";
        tmp.push_back(s[i]);
        for(int j=i+1;j<n;j++) {
            tmp.push_back(s[j]);
            for(int k=j+1;k<n;k++) {
                tmp.push_back(s[k]);
                ans += (i + k == 2*j && tmp == "ABC");
                tmp.pop_back();
            }
            tmp.pop_back();
        }
        tmp.pop_back();
    }
    return cout<<ans,0;
}