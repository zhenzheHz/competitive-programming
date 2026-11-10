// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=e535
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool is_2(string x) {
    return ((x.back() - '0') % 2 == 0);
}
bool is_3(string x) {
    int sum = 0;
    for(auto digit : x) {
        sum += digit - '0';
    }
    return sum % 3 == 0;
}
bool is_4(string x) {
    int sz = x.size();
    int a = x[sz-1] - '0';
    int b = x[sz-2] - '0';
    return (10*b + a) % 4 == 0;
}
bool is_5(string x) {
    return x.back() == '0' || x.back() == '5';
}
bool is_7(string x) {
    reverse(x.begin(), x.end());
    while(x.size() % 3 != 0) x.push_back('0');
    reverse(x.begin(), x.end());
    int diff = 0, sign = 1;
    for(int i = 0; i < (int) x.size(); i += 3, sign *= -1) {
        int a = x[i] - '0', b = x[i+1] - '0', c = x[i+2] - '0';
        diff += (100*a+10*b+c) * sign;
    }
    return abs(diff) % 7 == 0;
}
bool is_8(string x) {
    int sz = x.size();
    int a = x[sz-1] - '0', b = x[sz-2] - '0', c = x[sz-3] - '0';
    return (a+10*b+100*c) % 8 == 0;
}
bool is_9(string x) {
    int sum = 0;
    for(auto digit : x) {
        sum += digit - '0';
    }
    return sum % 9 == 0;
}
bool is_10(string x) {
    return x.back() == '0';
}
bool is_11(string x) {
    int diff = 0, sign = 1;
    for(int i = 0; i < (int) x.size(); i++, sign *= -1) {
        diff += sign * (x[i] - '0');
    }
    return abs(diff) % 11 == 0;
}
bool verify(string x, int p) {
    switch(p) {
        case 1: return 1;
        case 2: return is_2(x);
        case 3: return is_3(x);
        case 4: return is_4(x);
        case 5: return is_5(x);
        case 6: return is_2(x) && is_3(x);
        case 7: return is_7(x);
        case 8: return is_8(x);
        case 9: return is_9(x);
        case 10: return is_10(x);
        case 11: return is_11(x);
        case 12: return is_4(x) && is_3(x);
    };
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    string num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num >> k;
        bool flag = 1;
        for(int j = 0; j < k; j++) {
            int y;
            cin >> y;
            if(!verify(num,y)) flag = 0;
        }
        cout << num << " - " << (flag? "Wonderful" : "Simple") << ".\n";
    } 
    return 0;
}