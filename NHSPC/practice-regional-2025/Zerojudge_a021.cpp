// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=a021
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using integar = vector<int>;
void trim(integar &x) {
    while(x.size() > 1 && x.back() == 0) x.pop_back();
}
ostream& operator<<(ostream &o, integar &x) {
    for(int i = 0; i < (int) x.size(); i++) {
        o << x[i];
    }
    return o;
}
bool geq(const integar &A, const integar &B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = 0; i < (int) A.size(); i++) {
        if(A[i] == B[i]) continue;
        return A[i] > B[i];
    }
    return 1;
}
integar operator+(integar &A,integar &B) {
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    integar C;
    int16_t carry = 0;
    for(int i = 0; i < (int)max(A.size(), B.size()); i++) {
        int16_t a = (i < (int) A.size()? A[i] : 0);
        int16_t b = (i < (int) B.size()? B[i] : 0);
        int16_t sum = a + b + carry;
        C.push_back(sum % 10);
        carry = sum / 10;
    }
    C.push_back(carry);
    trim(C);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());
    return C;
}
integar operator-(integar &A, integar &B) {
    if(!geq(A,B)) swap(A,B);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    integar C;
    int16_t borrow = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        int a = A[i] - borrow;
        int b = (i < (int) B.size()? B[i] : 0);
        if(a < b) a += 10, borrow = 1;
        else borrow = 0;
        C.push_back(a - b);
    }
    trim(C);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());
    return C;
}
integar operator*(integar &A, integar &B) {
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    integar C(A.size() + B.size(), 0);
    for(int i = 0; i < (int) A.size(); i++) {
        int carry = 0;
        for(int j = 0; j < (int) B.size() || carry; j++) {
            int a = A[i], b = (j < (int) B.size()? B[j] : 0);
            int sum = C[i+j] + a * b + carry;
            C[i+j] = sum % 10;
            carry = sum / 10;
        }
    }
    trim(C);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());
    return C;
}
integar operator/(integar A,integar B) {
    integar quotient;
    if(!geq(A,B)) return {0};
    int k = A.size() - B.size();
    while(B.size() < A.size()) B.push_back(0);
    for(int i = 0; i <= k; i++) {
        int16_t l = -1, r = 10;
        while(l+1!=r) {
            integar m = {(l+r)/2};
            if(geq(A, B * m)) l = (l+r)/2;
            else r = (l+r)/2;
        }
        integar tmp = {l};
        integar C = B * tmp;
        A = A - C;
        B.pop_back();
        if(quotient.size() || l != 0)quotient.push_back(l);
    }
    // integar remainer = A;
    return quotient;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    char op;
    cin >> a >> op >> b;
    integar x,y;
    for(int i = 0; i < (int) a.size(); i++) x.push_back(a[i] - '0');
    for(int i = 0; i < (int) b.size(); i++) y.push_back(b[i] - '0');
    if(op == '+') {
        integar ans = x + y;
        cout << ans;
    }
    if(op == '-') {
        if(!geq(x,y)) {
            swap(x,y);
            cout << '-';
        }
        integar ans = x - y;
        cout << ans;
    }
    if(op == '*') {
        integar ans = x * y;
        cout << ans;
    }
    if(op == '/') {
        integar ans = x / y;
        cout << ans;
    }
    return 0;
}