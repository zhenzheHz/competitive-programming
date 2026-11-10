#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int>;
Integar operator*(Integar &a, Integar &b) {
    Integar A(a.rbegin(),a.rend());
    Integar B(b.rbegin(),b.rend());
    Integar C(a.size() + b.size() + 3,0);
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B.size();j++) {
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
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line;
    Integar res = {1};
    while(getline(cin,line)) {
        while(line.back() == '\r' || line.back() == '\n') line.pop_back();
        bool num = 1;
        for(auto ch : line) {
            if(!isdigit(ch)) {
                num = 0;
                break;
            }
        }
        if(num) {
            Integar c;
            for(int i=0;i<line.size();i++) {
                c.push_back(line[i] - '0');
            }
            res = res * c;
        }
    }
    for(auto ch : res) {
        cout << ch;
    }
    cout << '\n';
}