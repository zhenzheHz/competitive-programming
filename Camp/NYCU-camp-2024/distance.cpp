#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    #define int double
    int x1,x2,x3,y,y1,y2,y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int vectorAB_x = x2-x1;
    int vectorAB_y = y2-y1;
    int vectorAC_x = x3-x1;
    int vectorAC_y = y3-y1;
    int area = abs(vectorAB_x*vectorAC_y - vectorAB_y*vectorAC_x);
    // cerr << area << '\n';
    auto square = [](double x) { return x * x; };
    double base = sqrt(square(x2 - x3) + square(y2 - y3));
    // cerr << base;
    int dis = area/base;
    cout << fixed << setprecision(4) << dis;
}
