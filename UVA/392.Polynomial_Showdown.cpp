// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=c060
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
string format_polynomial(vector<int> coeffs) {
    string result;
    bool first_term = true;
    for (int i = 0; i < coeffs.size(); ++i) {
        int exp = coeffs.size() - i - 1;
        int coef = coeffs[i];
        if (coef == 0) continue;
        if (coef > 0 && !first_term) {
            result += " + ";
        } else if (coef < 0 && !first_term) {
            result += " - ";
        } else if (coef < 0 && first_term) {
            result += "-";
        }
        if (abs(coef) != 1 || exp == 0) { 
            result += to_string(abs(coef));
        }
        if (exp > 1) {
            result += "x^" + to_string(exp);
        } else if (exp == 1) {
            result += "x";
        }

        first_term = false;
    }
    if (result.empty()) result = "0";
    return result;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    vector<int> coeff(9);
    while (cin >> coeff[0]) {
        for(int i = 1; i < 9; i++) {
            cin >> coeff[i];
        }
        cout << format_polynomial(coeff) << '\n';
    }
    return 0;
}
