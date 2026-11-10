// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2020 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2224
#include <bits/stdc++.h>
#define int int64_t
#define p first
#define w second
using namespace std;
pair<int,int> thing[1005];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> thing[i].w >> thing[i].p;
    }
    sort(thing, thing+n);
    reverse(thing, thing+n);
    int value = 0, weight = 0;
    for(int i=0;i<n;i++) {
        if(weight >= m) break;
        int k = min(m-weight, thing[i].w);
        weight += k;
        value += thing[i].p * k;
    }
    cout << value << '\n';
}