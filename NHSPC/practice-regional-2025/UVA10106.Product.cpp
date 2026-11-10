// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=d380
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int16_t>;
Integar operator*(const Integar &A, const Integar &B) {
    Integar C(A.size() + B.size(), 0);
    for(size_t i = 0; i < A.size(); i++) {
        int16_t carry = 0;
        for(size_t j = 0; j < B.size() || carry; j++) {
            int a = A[i], b = (j < B.size()? B[j] : 0);
            int product = C[i+j] + a * b + carry;
            C[i+j] = product % 10;
            carry = product / 10;
        }
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
void Convert(Integar &I, string &k) {
    if(k == "0") return I = {0},void();
    I.clear();
    for(int i = k.size() - 1; i >= 0; i--) {
        I.push_back(k[i] - '0');
    }
}
void operator<<(ostream &o, const Integar &P) {
    for(int i = P.size() - 1; i >= 0; i--) {
        o << P[i];
    }
    o << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    Integar x,y;
    while(cin >> a >> b) {
        Convert(x,a);
        Convert(y,b);
        Integar ans = x*y;
        cout << ans;
    }
    return 0;
}