// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2252
#include <bits/stdc++.h>
#define int int64_t
#define x first
#define y second
using namespace std;
using Point = pair<int,int>;
Point pt[105];
Point operator-(Point A,Point B) { return {A.x-B.x,A.y-B.y}; }
int dot(Point A, Point B) { return A.x*B.x+A.y*B.y; }
int cross(Point A,Point B) { return abs(A.x*B.y-A.y*B.x); }
double dis(Point A,Point B) { return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2)); }
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    Point st; int n;
    cin >> st.x >> st.y >> n;
    n++;
    double ans = 1e18;
    for(int i = 0; i < n; i++) cin >> pt[i].x >> pt[i].y;
    for(int i = 1; i < n; i++) {
        Point A = pt[i-1], B = pt[i], P = st;
        Point AB = B - A, BA = A - B, AP = P - A, BP = P - B;
        if(dot(AB,AP) < 0 || dot(BA,BP) < 0) {
            ans = min({ans, dis(A,P), dis(B,P)});
        }
        else {
            ans = min(ans, cross(AB,AP) / 1.0 / dis(A,B));
        }
    }
    return cout<<fixed<<setprecision(20)<<ans,0;
}
