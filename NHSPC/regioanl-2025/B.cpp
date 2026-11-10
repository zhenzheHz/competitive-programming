#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const int day1[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const int day2[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
const int x1[] = {0,40,20,15}, x2[] = {0,60,40,20};
int level,num,year,month,date;
bool is_leap_year(int y) {
    if(y % 4 == 0 && y % 100 != 0) return 1;
    if(y % 400 == 0) return 1;
    return 0;
}
void print() {
    cout << year << '/' << month << '/' << date;
}
void pass_time(int day) {
    while(day > 0) {
        int remain = (is_leap_year(year)? day2[month] : day1[month]) - date;
        if(remain >= day) {
            date += day;
            day = 0;
        }
        else {
            day -= remain + 1;
            date = 1;
            if(++month == 13) {
                month = 1;
                year += 1;
            }
        }
    } 
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> level >> num >> year >> month >> date;
    pass_time(is_leap_year(year)? 366 : 365);
    print();
    cout << '\n';
    pass_time(x1[level]);
    print();
    cout << ' ' << num/100+(num%100!=0) << '\n';
    pass_time(10);
    print();
    cout << '\n';
    pass_time(x2[level]);
    print();
    cout << ' ' << num/10+(num%10!=0) << '\n';
    pass_time(10);
    print();
    cout << '\n';
    pass_time(10);
    print();
    cout << ' ' << num/4+(num%4!=0) << '\n';
}
