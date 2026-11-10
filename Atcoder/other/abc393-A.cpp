// Problem : https://atcoder.jp/contests/abc393/tasks/abc393_a
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string s1,s2;
    cin >> s1 >> s2;
    bool a = (s1 == "sick"), b = (s2 == "sick");
    int ans;
    if(a && b) ans = 1;
    if(a && !b) ans = 2;
    if(!a && b) ans = 3;
    if(!a && !b) ans = 4;
    return cout<<ans,0;
}