#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Point { 
    int x, y;
};
struct Triangle {
    Point A,B,C;
};
int cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool inside(Triangle T, Point p) {
    Point a = T.A;
    Point b = T.B;
    Point c = T.C;
    int c1 = cross(a, b, p);
    int c2 = cross(b, c, p);
    int c3 = cross(c, a, p);
    bool pos = (c1 > 0 && c2 > 0 && c3 > 0);
    bool neg = (c1 < 0 && c2 < 0 && c3 < 0);
    bool on = (c1 == 0 || c2 == 0 || c3 == 0);
    return pos || neg || on;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    Triangle tri;
    vector<Triangle> ts;
    int a,b,c,d,e,f;
    while(cin >> a >> b >> c >> d >> e >> f) {
        tri = {{a,b},{c,d},{e,f}};
        ts.push_back(tri);
    }
    int ans = 0;
    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            int mark = 0;
            for(auto &t : ts) {
                bool a = inside(t, {i,j});
                bool b = inside(t, {i+1,j});
                bool c = inside(t, {i,j+1});
                bool d = inside(t, {i+1,j+1});
                bool check = a && b && c && d;
                if(check) {
                    mark = 1;
                    break;
                }
            }
            if(mark) ans += 1;
        }
    }
    cout << ans;
}