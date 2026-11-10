// Problem : https://cses.fi/problemset/task/1753
// Tags : KMP
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string str,sub;
    cin >> str >> sub;
    vector<int> next(sub.size(),0);
    for(int i=1,now=0;i<sub.size();) {
        if(sub[i] == sub[now]) 
            next[i] = ++now, i++;
        else if(now == 0)
            next[i] = 0, i++;
        else
            now = next[now-1];
    }
    int ans = 0;
    for(int i=0,j=0;i<str.size();) {
        if(str[i] == sub[j])
            i += 1, j += 1;
        else if(j > 0)
            j = next[j-1];
        else
            i += 1;
        if(j == sub.size()) {
            ans += 1, j = next[j-1];
        }
    }
    return cout<<ans,0;
}