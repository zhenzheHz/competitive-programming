// Author : Zhenzhe
// Time : 2024 / 11 / 05
// Problem : https://zerojudge.tw/ShowProblem?problemid=d190
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void merge_sort(vector<int> &arr, int left, int right) {
    if(left == right) return void();
    int mid = (left+right) >> 1;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    vector<int> left_part(arr.begin()+left,arr.begin()+mid+1);
    vector<int> right_part(arr.begin()+mid+1,arr.begin()+right+1);
    left_part.push_back(1e18);
    right_part.push_back(1e18);
    int lptr = 0, rptr = 0, index = left;
    while(index <= right) {
        if(left_part[lptr] < right_part[rptr]) {
            arr[index++] = left_part[lptr++];
        }else {
            arr[index++] = right_part[rptr++];
        }
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    while(cin >> n && n) {
        vector<int> Array(n);
        for(int &i : Array) cin >> i;
        merge_sort(Array,0,n-1);
        for(int &i : Array) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}