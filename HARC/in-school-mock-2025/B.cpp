#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string code;
    getline(cin,code);
    string ans = "";
    for(size_t i=0;i<code.size();i++) {
        if(code[i] == '1' || code[i] == '2') {
            int index = (code[i]-'0') * 10 + (code[i+1]-'0');
            ans.push_back('A'+index-1);
            i += 1;
        }
        else {
            int index = (code[i]-'0');
            ans.push_back('A'+index-1);
        }
    }
    cout << ans << '\n';
    return 0;
}