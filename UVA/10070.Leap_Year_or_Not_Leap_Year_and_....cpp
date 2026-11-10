// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=d047
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool is_leap_year(string &year) {
    // check 4,100,400
    int Convert = (year[year.size()-2] - '0') * 10 + (year.back()-'0');
    if(Convert % 4 == 0) {
        if(Convert == 0) {
            Convert = (year[year.size()-4] - '0') * 10 + (year[year.size()-3] - '0');
            return Convert%4 == 0;
        }
        else return true;
    }
    else return false;
}
bool is_huluculu(string &year) {
    if(year.back() != '5' && year.back() != '0')
        return false;
    int sum = 0;
    for(auto digit : year) {
        sum += digit - '0';
    }
    return sum%3 == 0;
}
bool is_bulukulu(string &year) {
    if(!is_leap_year(year)) 
        return false;
    if(year.back() != '5' && year.back() != '0')
        return false;
    int sum = 0, sign = 1;
    for(auto digit : year) {
        sum += (digit-'0') * sign;
        sign *= -1;
    }
    sum = abs(sum);
    return sum % 11 == 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string test;
    while(cin >> test) {
        int ans = 0;
        if(is_leap_year(test))
            cout << "This is leap year.\n", ans += 1;
        if(is_huluculu(test))
            cout << "This is huluculu festival year.\n", ans += 1;
        if(is_bulukulu(test))
            cout << "This is bulukulu festival year.\n", ans += 1;
        if(!ans) cout << "This is an ordinary year.\n";
        cout << '\n';
    }
}