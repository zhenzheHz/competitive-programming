// Problem : https://codeforces.com/contest/630/problem/O
// Tags : Geometry
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<pair<double,double>> points(8);
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x,y,vx,vy,a,b,c,d;
    double k;
    cin >> x >> y >> vx >> vy;
    cin >> a >> b >> c >> d;
    double lenV = sqrt(vx*vx+vy*vy);
    k = b / lenV;
    points[1] = {(double)x + k*vx, (double)y + k*vy};
    int nx = -vy,ny = vx;
    k = (a / 2.0) / lenV;
    points[2] = {(double)x + k*nx, (double)y + k*ny};
    points[7] = {(double)x - k*nx, (double)y - k*ny};
    k = (c / 2.0) / lenV;
    double dx = k*nx, dy = k*ny;
    points[3] = {x+dx, y+dy};
    points[6] = {x-dx, y-dy};
    k = d / lenV;
    points[4] = {x+dx-k*vx, y+dy-k*vy};
    points[5] = {x-dx-k*vx, y-dy-k*vy};
    for(int i=1;i<=7;i++) {
        cout << fixed << setprecision(15) << points[i].first << ' ' << points[i].second;
        cout << '\n';
    }
}