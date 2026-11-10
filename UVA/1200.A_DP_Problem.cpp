// Author : Zhenzhe
// Time : 2024 / 10 / 28
// Problem : https://zerojudge.tw/ShowProblem?problemid=e547
#include <bits/stdc++.h> 
#define int int64_t
using namespace std;
struct Poly{
    string str;
    int cof = 0, constant = 0;
    explicit Poly(string s):str(s){
        string tmp = "";
        vector<string> num;
        for(int i=0;i<s.size();i++) {
            if(isdigit(s[i]) || s[i] == 'x') {
                tmp.push_back(s[i]);
            }else {
                assert(s[i] == '+' || s[i] == '-');
                num.push_back(tmp);
                tmp = "";
                if(s[i] == '-') tmp.push_back('-');
            }
        }
        if(tmp.size()) num.push_back(tmp);
        for(auto element : num) {
            // cerr << element << ' ';
            string copy = element;
            if(element.back() == 'x') {
                copy.pop_back();
                if(copy.empty()) copy = "1";
                else if(copy.back() == '-') copy.push_back('1');
                int k = stoi(copy);
                cof += k;
            }else constant += stoi(copy);
        }
    }
};
void solve();
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}
void solve() {
    string equation;
    // getline(cin,equation);
    cin >> equation;
    while(equation.back() == '\r') equation.pop_back();
    int index = -1;
    for(int i=0;i<equation.size();i++) {
        if(equation[i] == '=') {
            index = i;
            break;
        }
    }
    string left(equation.begin(),equation.begin()+index);
    string right(equation.begin()+index+1,equation.end());
    // cerr << left << ' ' << right << '\n';
    Poly L(left), R(right);
    int cof_x = L.cof - R.cof;
    int cof_c = R.constant - L.constant;
    if(cof_x == 0 && cof_c == 0) return cout<<"IDENTITY\n",void();
    if(cof_x == 0 && cof_c != 0) return cout<<"IMPOSSIBLE\n",void();
    int ans = cof_c / cof_x;
    if(cof_c % cof_x != 0 && ans < 0) {
        ans -= 1;
    }
    // cerr << cof_x << ' ' << cof_c << '\n';
    cout << ans << '\n';
}