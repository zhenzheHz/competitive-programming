// Problem : https://codeforces.com/contest/215/problem/B
// Tags : Greedy
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    int r1, p1, p2, A, B, c;
    vector<int> x,y,z;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c;
        x.push_back(c);
    }
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c;
        y.push_back(c);
    }
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c;
        z.push_back(c);
    }
    r1 = *max_element(x.begin(), x.end());
    p1 = *max_element(y.begin(), y.end());
    p2 = *min_element(z.begin(), z.end());
    cin >> A >> B;
    const double sum = A * p2 + B * p1;
    double r2 = sqrt(B * r1 * r1 * p1 / (1.0 * sum));
    return cout<<fixed<<setprecision(15)<<r2,0;
}