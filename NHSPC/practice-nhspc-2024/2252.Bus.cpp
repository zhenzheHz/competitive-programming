// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2021 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2252
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using point = pair<double,double>;
point start;
int n;
double len(const point &v) {return v.x*v.x+v.y*v.y;}
double dot(const point &a, const point &b) {return a.x*b.x  + a.y*b.y;}
double cross(const point &a,const point &b) {return abs(a.x*b.y - a.y*b.x);}
point operator-(const point &a,const point &b) {return make_pair(a.x-b.x,a.y-b.y);} 
double dis(const point &a,const point &b) {return sqrt(len(a-b));}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> start.x >> start.y >> n;
    vector<point> pt(n+1);
    for(auto &i : pt) cin >> i.x >> i.y;
    double ans = 1e18;
    for(int i=0;i<n;i++) {
        point A = pt[i], B = pt[i+1];
        point AB = B - A, BA = A - B;
        point AP = start - A, BP = start - B;
        if(dot(AB,AP) < 0 || dot(BA,BP) < 0)
            ans = min({ans, dis(A,start), dis(B,start)});
        else
            ans = min(ans, cross(AB,AP)/dis(A,B));
    }
    cout << fixed << setprecision(15) << ans << '\n';
}