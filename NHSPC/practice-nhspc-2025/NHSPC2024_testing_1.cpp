// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=g051
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using Point = pair<int,int>;
bool collinear(Point &A, Point &B, Point &C) {
    Point AB = {B.x - A.x, B.y - A.y};
    Point AC = {C.x - A.x, C.y - A.y};
    return (AB.x * AC.y == AB.y * AC.x);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Point> Pt(n);
    for(auto &[x,y] : Pt) cin >> x >> y;
    mt19937 engine(random_device{}());
    uniform_int_distribution<int> rand_idx(0,n-1);
    int iter = 1000;
    int ans = 0;
    for(int it = 0; it < iter; it++) {
        int cnt = 0;
        int i = rand_idx(engine), j = rand_idx(engine);
        while(i == j) j = rand_idx(engine);
        for(int k = 0; k < n; k++) {
            cnt += collinear(Pt[i],Pt[j],Pt[k]);
        }
        ans = max(ans, cnt);
    }
    return cout<<ans,0;
}