// Author : Zhenzhe
// Time : 2024 / 11 / 02
// Problem : https://zerojudge.tw/ShowProblem?problemid=a539
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int SIZE = 0;
    while(cin >> SIZE) {
        vector<int> Array(SIZE);
        int times_of_swap = 0;
        for(int &i : Array) cin >> i;
        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE-i-1;j++) {
                if(Array[j] > Array[j+1]) {
                    swap(Array[j],Array[j+1]);
                    times_of_swap++;
                }
            }
        }
        cout << "Minimum exchange operations : " << times_of_swap << '\n';
    }
}