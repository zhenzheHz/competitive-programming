// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=d056
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve();
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 0;
    scanf ("%lld", &test);
    while(test--) {
        solve();
    }
}
void solve() {
    int n;
    scanf ("%lld", &n);
    vector<int> sum;
    for(int i=0;i<n;i++) {
        int a,b;
        scanf ("%lld %lld", &a, &b);
        sum.push_back(a+b);
    }
    for(int i=sum.size()-1;i>0;i--) {
        sum[i-1] += sum[i]/10;
        sum[i] %= 10;
    }
    for(auto digit : sum) {
        cout << digit;
    }
    cout << "\n\n";
}