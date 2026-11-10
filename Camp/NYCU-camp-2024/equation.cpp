#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    double a,b,c;
    cin >> a >> b >> c;
    double d = sqrt(b*b-4*a*c);
    double root1 = (-b + d)/(2*a);
    double root2 = (-b - d)/(2*a);
    cout << fixed << setprecision(4) << root1 << '\n';
    cout << fixed << setprecision(4) << root2 << '\n';
}
