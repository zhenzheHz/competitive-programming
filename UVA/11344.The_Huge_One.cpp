// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=e535
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool inspect(string &num,int f) {
    if(num.size() == 1 && num.back() == '0') return 1;
    string rev(num.rbegin(),num.rend());
    int diff,s,sign,k,x;
    if(num.size() <= 4) 
        return stoi(num) % f == 0;
    switch (f) {
        case 1:
            return 1;
        case 2:
            return (num.back()-'0')%2 == 0;
        case 3:
            diff = 0;
            for(auto c : num) diff += c-'0';
            return abs(diff) % 3 == 0;
        case 4:
            s = num[num.size()-1] - '0';
            if(num.size() >= 2) s += (num[num.size()-2]-'0') * 10;
            return s%4 == 0;
        case 5:
            return num.back() == '5' || num.back() == '0';
        case 6:
            return inspect(num,2) && inspect(num,3);
        case 7:
            while(rev.size() % 3 != 0) rev.push_back('0');
            reverse(rev.begin(),rev.end());
            diff = 0, sign = 1;
            for(int i=0;i<rev.size();i+=3,sign *= -1) {
                diff += ((rev[i]-'0')*100 + (rev[i+1]-'0')*10 + (rev[i+2]-'0')) * sign;
            }
            return abs(diff)%7==0;
        case 8:
            k = num.size();
            x = (num[k-3]-'0')*100 + (num[k-2]-'0')*10 + (num[k-1]-'0');
            return x%8==0;
        case 9:
            diff = 0;
            for(auto c : num) diff += c-'0';
            return abs(diff) % 9 == 0;
        case 10:
            return num.back() == '0';
        case 11:
            diff = 0,sign = 1;
            for(int i=0;i<num.size();i++,sign*=-1) {
                diff += sign * (num[i]-'0');
            }
            return abs(diff)%11==0;
        case 12:
            return inspect(num,3) && inspect(num,4);
        default:
            return true;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string test,tmp;
    int T,Set;
    cin >> T;
    while(T--) {
        cin >> test;
        cin >> Set;
        int f;
        vector<int> Union;
        for(int i=0;i<Set;i++) {
            cin >> f;
            Union.push_back(f);
        }
        bool check = true;
        for(auto k : Union) {
            if(!inspect(test,k)) {
                check = false;
                break;
            }
        }
        cout << test << " - ";
        if(check) cout << "Wonderful.\n";
        else cout << "Simple.\n";
    }
}