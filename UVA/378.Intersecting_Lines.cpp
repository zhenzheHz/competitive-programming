// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c113
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using Point = pair<double,double>;
double operator*(Point &a, Point &b) {
    return abs(a.x*b.y-a.y*b.x);
}
Point operator-(Point &a, Point &b) {
    return {a.x-b.x,a.y-b.y};
}
void solve();
int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cout << "INTERSECTING LINES OUTPUT\n";
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
void solve() {
    Point a,b,c,d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    if((a.y-b.y)*(c.x-d.x) == (c.y-d.y)*(a.x-b.x)) {
        if((a.y-b.y)*(a.x-c.x) == (a.y-c.y)*(a.x-b.x))
            return cout<<"LINE\n",void();
        else
            return cout<<"NONE\n",void();
    } 
    Point AC = c-a,AD = d-a,BC = c-b,BD = d-b;
    double AE =  AC*AD, BE = BC*BD;
    double t = AE/(AE+BE);
    // cout << t << '\n';
    Point AB = b-a;
    Point ans;
    ans.x = a.x + t*AB.x;
    ans.y = a.y + t*AB.y;
    cout << fixed << setprecision(2) << "POINT " << ans.x << ' ' << ans.y << '\n';
}