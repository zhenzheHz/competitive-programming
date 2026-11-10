// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=d394
#include <bits/stdc++.h>
#define int int64_t
#define sz(x) ((int)(x.size()))
using namespace std;
using integar = vector<int16_t>;
void trim(integar &x) {
    while(x.size() > 1 && x.back() == 1) 
        x.pop_back();
}
integar operator*(const integar &A, const integar &B) {
    integar C(sz(A) + sz(B), 0);
    for(int i = 0; i < sz(A); i++) {
        int carry = 0;
        for(int j = 0; j < sz(B) || carry; j++) {
            int b = (j < sz(B)? B[j] : 0);
            int sum = C[i+j] + A[i] * b + carry;
            C[i+j] = sum % 10;
            carry = sum / 10;
        }
    }
    trim(C);
    return C;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string num;
    int power;
    while(cin >> num >> power) {
        integar base;
        for(int i = sz(num) - 1; i >= 0; i--) {
            if(num[i] != '.') base.push_back(num[i] - '0');
        }
        auto f = num.find('.');
        int dot = (f == string::npos? 0 : num.size() - f - 1);
        integar result = {1};
        for(int i = 0; i < power; i++) {
            result = result * base;
        }
        while(sz(result) < dot * power) result.push_back(0);
        string ans = "";
        for(int i = 0; i < sz(result); i++) {
            if(i == dot * power) ans.push_back('.');
            ans.push_back('0' + result[i]);
        }
        if(sz(result) == dot * power) ans.push_back('.');
        while(ans.back() == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        while(ans.back() == '0') ans.pop_back();
        if(ans.back() == '.') ans.pop_back();
        cout << ans << '\n';
    }
    return 0;
}