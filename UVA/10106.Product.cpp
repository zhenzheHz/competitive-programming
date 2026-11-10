// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=d380
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int>;
Integar operator*(const Integar &L, const Integar &R) {
    const Integar A(L.rbegin(), L.rend()), B(R.rbegin(),R.rend());
    Integar C;
    C.resize(A.size() + B.size() + 3,0);
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B.size();j++) {
            C[i+j] += A[i] * B[j];
        }
    }
    for(int i=0;i<C.size()-1;i++) {
        C[i+1] += C[i]/10;
        C[i] %= 10;
    }
    while(C.back() == 0) C.pop_back();
    if(C.empty()) C.push_back(0);
    return Integar(C.rbegin(),C.rend());
}
void Convert(Integar &V, string &s) {
    V.clear();
    for(auto c : s) {
        V.push_back(c-'0');
    }
}
void operator<<(ostream &o, Integar s) {
    for(auto c : s) {
        cout << c;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string ta,tb;
    Integar a,b;
    while(cin >> ta >> tb) {
        Convert(a, ta);
        Convert(b, tb);
        Integar C = a*b;
        cout << C;
        cout << '\n';
    }
}