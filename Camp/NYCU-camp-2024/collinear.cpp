#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    #define int double
    auto equal = [&](int &a,int &b){
        return fabs(a - b) < 1e-6;
    };
    auto solve = [&](int a,int b){
        if(equal(a,b))cout << "Collinear";
        else cout << "General Position";
    };
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(equal(x1,x2) || equal(x1,x3)){
        if(equal(x1,x2) && equal(x1,x3))cout << "Collinear";
        else cout << "General Position";
        return 0;
    }
    int slopeAB = (y1-y2)/(x1-x2);
    int slopeAC = (y1-y3)/(x1-x3);
    solve(slopeAB,slopeAC);
}
