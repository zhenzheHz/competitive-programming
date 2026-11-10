// Problem : https://tioj.ck.tp.edu.tw/problems/1497
// Tags : Suffix array
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string str;
    getline(cin, str);
    const int n = str.size();
    const int logN = 32 - __builtin_clz(n);
    vector<int> rk(n+1, -1);
    vector<pair<pair<int,int>,int>> v(n, {{0,0},0});
    for(int i=0;i<n;i++) v[i] = {{str[i],0},i};
    for(int k=0;k<=logN;k++) {
        int now = 1 << k;
        sort(v.begin(), v.end());
        rk[v[0].second] = 0;
        for(int i=1;i<n;i++) {
            rk[v[i].second] = (v[i].first == v[i-1].first? rk[v[i-1].second] : i);
        }
        for(int i=0;i<n;i++) {
            v[i] = {{rk[i], rk[min(n,i+now)]}, i};
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++) {
        cout << v[i].second << '\n';
    }
    return 0;
}