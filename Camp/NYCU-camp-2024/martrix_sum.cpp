#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    int row,column;
    cin >> row >> column;
    vector<vector<int>> matrix(r,vector<int>(c,0));
    int TEST = 2;
    while(TEST--){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                int value;
                cin >> value;
                matrix[i][j] += value;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}
