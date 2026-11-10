// Author : Zhenzhe
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
string hidden,line,r,g,b;
int idx,R,G,B;
void inspect(string &x) {
    while(x.back() == '\r' || x.back() == '\n') x.pop_back();
}
void apply(int &A, int B) {
    if(idx >= (int) hidden.size()) return;
    if((A & 2) != (B & 2)) {
        A >>= 1;
        A <<= 1;
        A |= (hidden[idx] - '0');
    }
    idx++;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    while(getline(cin,hidden)) {
        getline(cin,line);
        inspect(hidden);
        inspect(line);
        stringstream ss;
        ss << line;
        idx = 0;
        while(ss >> r >> g >> b) {
            R = stoi(r), G = stoi(g), B = stoi(b);
            apply(R,G);
            apply(G,B);
            apply(B,R);
            cout << R << ' ' << G << ' ' << B << ' ';
        }
        cout << '\n';
    }
    return 0;
}