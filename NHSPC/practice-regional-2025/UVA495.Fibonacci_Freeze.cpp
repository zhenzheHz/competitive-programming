// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c121
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int16_t>;
Integar operator+(const Integar &A, const Integar &B) {
    Integar C;
    int16_t carry = 0;
    for(size_t i = 0; i < max(A.size(), B.size()); i++) {
        int16_t a = (i < A.size()? A[i] : 0);
        int16_t b = (i < B.size()? B[i] : 0);
        int sum = a + b + carry;
        C.push_back(sum % 10);
        carry = sum / 10;
    }
    if(carry) C.push_back(carry);
    return C;
}
void operator<<(ostream &o, const Integar &P) {
    for(int i = P.size()-1; i >= 0; i--) {
        o << P[i];
    }
    o << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    Integar F[5005];
    F[0] = {0}, F[1] = {1};
    for(int i = 2; i <= 5000; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    while(cin >> n) {
        cout << "The Fibonacci number for " << n << " is ";
        cout << F[n];
    }
    return 0;
}