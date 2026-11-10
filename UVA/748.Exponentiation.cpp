#include <bits/stdc++.h>
using namespace std;
string operator*(string &a, string &b) {
    //while(a.back() == '0') a.pop_back();
    //while(b.back() == '0') b.pop_back();
    string A(a.rbegin(),a.rend()), B(b.rbegin(),b.rend());
    vector<int> C(a.size()+b.size()+1, 0);
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B.size();j++) {
            C[i+j] += (A[i]-'0') * (B[j]-'0');
        }
    }
    for(int i=0;i<C.size()-1;i++) {
        if(C[i] > 9) {
            C[i+1] += C[i]/10;
            C[i] %= 10;
        }
    }
    while(C.back() == 0) C.pop_back();
    reverse(C.begin(),C.end());
    string result = "";
    for(int i=0;i<C.size();i++) {
        char x = '0' + C[i];
        result.push_back(x);
    }
    return result;
}
void solve(string base,int ep);
int split(string &base);
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string base;
    int ep;
    while(cin >> base >> ep) {
        solve(base,ep);
    }
}
int split(string &base) {
    int position = base.find('.');
    int RETURN = base.length() - position - 1;
    if(position != string::npos) 
        base.erase(position,1);
    return RETURN;
}
void solve(string base, int ep) {
    int k = split(base);
    string result = base;
    for(int i=1;i<ep;i++) {
        result = result * base;
    }
    for(int i=0;i<result.size()-k*ep;i++) {
        cout << result[i];
    }
    cout << '.';
    int x = result.size() - k*ep;
    while(result.back() == '0') result.pop_back();
    for(int i=x;i<result.size();i++) {
        cout << result[i];
    }
    cout << '\n';
}