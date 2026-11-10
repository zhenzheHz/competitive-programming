#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t times;cin >> times;
    int hours = times/3600;
    times %= 3600;
    int minutes = times/60;
    int seconds = times%60;
    cout << hours << '\n';
    cout << minutes << '\n';
    cout << seconds << '\n';
}

