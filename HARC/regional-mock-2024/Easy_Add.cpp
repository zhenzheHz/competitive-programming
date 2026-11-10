#include <bits/stdc++.h>
#define int int64_t
using namespace std;
string operator+(string &a,string &b) {
    string A(a.rbegin(),a.rend()), B(b.rbegin(),b.rend());
    if(A.size() < B.size()) swap(A,B);
    while(A.size() > B.size()) B.push_back('0');
    vector<int> C(A.size()+2,0);
    for(int i=0;i<A.size();i++) {
        C[i] = A[i]-'0' + B[i]-'0';
    }
    for(int i=0;i<C.size()-1;i++) {
        if(C[i] > 9) {
            C[i+1] += C[i] / 10;
            C[i] %= 10; 
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    string s = "";
    for(int i=C.size()-1;i>=0;i--) {
        char u = '0' + C[i];
        s.push_back(u);
    }
    return s;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line;
    while(getline(cin,line)) {
        string ans = "0";
        while(line.back() == '\n' || line.back() == '\r') line.pop_back();
        if(line.size() == 0) break;
        stringstream ss;
        ss << line;
        string tmp;
        while(ss >> tmp) {
            ans = ans + tmp;
        }
        cout << ans << '\n';
    }
}