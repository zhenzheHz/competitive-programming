// Author : Zhenzhe
// Times : 2024 / 10 / 14
// Problem : https://zerojudge.tw/ShowProblem?problemid=c203
#include <bits/stdc++.h>
using namespace std;
void solve(int32_t test);
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int32_t test = 1;
    cin >> test;
    while(test--) {
        int32_t n;
        cin >> n;
        solve(n);
    }
}
void solve(int32_t test) {
    int64_t sum = 1;
    for(int32_t i=2; i*i<=test; i++) {
        if(test%i == 0) {
            sum += i;
            if(i*i != test) sum += test/i;
        }
    }
    if(sum == test) return cout<<"perfect\n",void();
    if(sum > test) return cout<<"abundant\n",void();
    if(sum < test) return cout<<"deficient\n",void();
}