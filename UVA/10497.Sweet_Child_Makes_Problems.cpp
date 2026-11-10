// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=d443
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int>;
Integar operator+(Integar &a,Integar &b) {
    Integar A(a.rbegin(),a.rend());
    Integar B(b.rbegin(),b.rend());
    if(A.size() < B.size()) swap(A,B);
    while(B.size() < A.size()) B.push_back(0);
    Integar C;
    for(int i=0;i<A.size();i++) {
        C.push_back(A[i]+B[i]);
    }
    C.push_back(0);
    for(int i=0;i<C.size();i++) {
        if(C[i] > 9) {
            C[i+1] += C[i] / 10;
            C[i] %= 10; 
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return Integar(C.rbegin(),C.rend());
}
Integar operator*(Integar &a,Integar &b) {
    Integar A(a.rbegin(),a.rend());
    Integar B(b.rbegin(),b.rend());
    Integar C(A.size()+B.size()+3,0);
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B.size();j++) {
            C[i+j] += A[i] * B[j];
        }
    }
    for(int i=0;i<C.size();i++) {
        if(C[i] > 9) {
            C[i+1] += C[i] / 10;;
            C[i] %= 10;
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return Integar(C.rbegin(),C.rend());
}
void operator<<(ostream &o, Integar &x) {
    for(auto k : x) {
        cout << k;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    Integar dp[900];
    dp[1] = {0},dp[2] = {1};
    for(int i=3;i<802;i++) {
        Integar k = dp[i-1] + dp[i-2];
        Integar t = {i-1};
        Integar res = t*k;
        dp[i] = res;
    }
    int test = 1;
    while(cin >> test) {
        if(test == -1) break;
        cout << dp[test];
        cout << '\n';
    }
}