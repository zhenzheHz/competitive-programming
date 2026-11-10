// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=b265
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        map<array<int,5>,int> lecture;
        for(int i=0;i<n;i++) {
            array<int,5> arr;
            for(int j=0;j<5;j++) cin >> arr[j];
            sort(arr.begin(),arr.end());
            lecture[arr] += 1;
        }
        int Max = 0,ans = 0;
        for(auto course : lecture) {
            Max = max(course.second,Max);
        }
        for(auto course : lecture) {
            ans += (course.second == Max) * course.second;
        }
        cout << ans << '\n';
    }
}