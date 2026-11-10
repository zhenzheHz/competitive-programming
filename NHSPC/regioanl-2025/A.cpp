#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string _age, _bmi, _bmp;
        cin >> _age >> _bmi >> _bmp;
        bool isPrint = 0;
        for(auto ch : _age) {
            if(ch == '.') {
                isPrint = 1;
                break;
            }
        }
        for(auto ch : _bmp) {
            if(ch == '.') {
                isPrint = 1;
                break;
            }
        }
        if(isPrint) {
            cout << -1 << '\n';
            continue;
        }
        int age = stoi(_age), bmp = stoi(_bmp);
        double bmi = stod(_bmi);
        if(70 <= age && age < 120 || bmi >= 50) {
            cout << "high risk\n";
        }
        else if(50 <= age && age < 60 && 40 <= bmp && bmp < 50) {
            cout << "medium risk\n";
        }
        else if((18.5 <= bmi && bmi<= 24) || (30 <= bmp && bmp < 40)) {
            cout << "low risk\n";
        }
        else {
            cout << -1 << '\n';
        }
    }
}
