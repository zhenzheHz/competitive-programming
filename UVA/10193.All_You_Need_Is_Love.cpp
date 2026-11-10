// Author : Zhenzhe
// Time : 2024 / 11 / 01
// Problem : https://zerojudge.tw/ShowProblem?problemid=d306
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve();
int Convert_to_decimal(const string binary) {
    int sum = 0;
    for(int power_of_2 = 1, i = binary.size()-1; i>=0; i--) {
        if(binary[i] == '1') {
            sum += power_of_2;
        }
        power_of_2 *= 2;
    }
    return sum;
}
int gcd(int a,int b) {
    if(b == 0) return a;
    else return gcd(b,a%b);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}
int CASE = 1;
void solve() {
    string a, b;
    cin >> a >> b;
    int A = Convert_to_decimal(a);
    int B = Convert_to_decimal(b);
    // if(a < b) swap(a,b);
    // cout << a << ' ' << b << '\n';
    int GCD = gcd(A,B);
    cout << "Pair #" << CASE++ << ":";
    if(GCD != 1) cout << " All you need is love!\n";
    else cout << " Love is not all you need!\n";
}