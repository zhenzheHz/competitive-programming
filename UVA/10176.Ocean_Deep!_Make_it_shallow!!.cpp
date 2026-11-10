// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=e638
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = string;
Integar operator*(const Integar &a, int &b) {
    Integar A(a.rbegin(),a.rend());
    vector<int> C;
    for(int i=0;i<A.size();i++) {
        C.push_back(A[i]-'0');
        C[i] *= b;
    }
    C.push_back(0);
    for(int i=0;i<C.size();i++) {
        C[i+1] += C[i] / 10;
        C[i] %= 10;
    }
    while(C.back() == 0) C.pop_back();
    Integar outcome = "";
    reverse(C.begin(),C.end());
    for(int i=0;i<C.size();i++) {
        outcome.push_back(C[i]+'0');
    }
    return outcome;
}
Integar operator-(const Integar &a, const Integar &b) {
    Integar A(a.rbegin(),a.rend()),B(b.rbegin(),b.rend());
    vector<int> C;
    while(B.size() < A.size()) B.push_back('0');
    for(int i=0;i<A.size();i++) {
        C.push_back((A[i]-'0')-(B[i]-'0'));
        // cout << C[i] << '\n';
    }
    for(int i=0;i<C.size()-1;i++) {
        if(C[i] < 0) {
            C[i+1] -= 1;
            C[i] += 10;
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    Integar outcome = "";
    for(int i=C.size()-1;i>=0;i--) {
        //
        // cout << C[i] << '\n';
        //
        outcome.push_back(C[i]+'0');
    }
    return outcome;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    
}