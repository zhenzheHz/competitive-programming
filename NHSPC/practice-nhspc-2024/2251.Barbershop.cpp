// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2021 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2251
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    sort(arr.begin(),arr.end());
    for(int t=0;t<2;t++) for(int i=1;i<n;i++) 
        arr[i] += arr[i-1];
    cout << arr.back() << '\n';
}