#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    string str;
    getline(cin,str);
    while(str.back() == '\r' || str.back() == '\n') str.pop_back();
    // step 1
    str = "NC-" + str;
    while(str.size() % 8 != 0) str.push_back('_');
    for(auto &ch : str) {
        if(isupper(ch)) ch = 'A' + (ch - 'A' + 3) % 26;
        if(islower(ch)) ch = 'a' + (ch - 'a' + 3) % 26;
        if(isdigit(ch)) ch = '0' + (ch - '0' + 5) % 10;
        if(ch == '_') ch = '#';
    }
    // cout << str << '\n';
    for(int i=0;i<(int)str.size();i++) {
        int r = i / 8 + 1;
        int cv = str[i] ^ r;
        if(cv >= 32 && cv <= 126) str[i] = (char) cv;
        else str[i] = '?';
        cout << str[i];
        if((i+1) % 8 == 0) cout << '\n';
    }
    cout << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string N;
    getline(cin,N);
    while(N.back() == '\r' || N.back() == '\n') N.pop_back();
    int n = stoi(N);
    while(n--) {
        solve();
    }
}