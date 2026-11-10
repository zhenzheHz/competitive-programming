// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=e679
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int>;
Integar operator*(const Integar &a, const Integar &b) {
    Integar A(a.rbegin(),a.rend()) , B(b.rbegin(),b.rend());
    Integar C(a.size() + b.size() + 3,0);
    for(int i=0;i<a.size();i++) {
        for(int j=0;j<b.size();j++) {
            C[i+j] += A[i] * B[j];
        }
    }
    for(int i=0;i<C.size()-1;i++) {
        if(C[i] > 9) {
            C[i+1] += C[i] / 10;
            C[i] %= 10;
        }
    }
    while(C.back() == 0) C.pop_back();
    return Integar(C.rbegin(),C.rend());
}
void operator<<(ostream &o, Integar &a) {
    for(auto c : a) {
        cout << c;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int base,power;
    while(cin >> base >> power) {
        if(base == 0 && power == 0) break;
        if(power == 0) {
            cout << 1 << '\n';
            continue;
        }
        Integar res = {1};
        Integar Base;
        if(base >= 10) Base = {1,0};
        else Base = {base};
        for(int i=0;i<power;i++) {
            res = res * Base;
        }
        cout << res;
        cout << '\n';
    }
}