// Author : Zhenzhe
// Time : 2024 / 11 / 02
// Problem : https://zerojudge.tw/ShowProblem?problemid=d762
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
char oper[3] = {'+','-','*'};
int Array[5];
bool dfs(int index,int cur) {
    if(index == 5) return cur==23;
    bool check = 0;
    if(dfs(index+1,cur+Array[index])) check = 1;
    if(dfs(index+1,cur-Array[index])) check = 1;
    if(dfs(index+1,cur*Array[index])) check = 1;
    return check;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    while(cin >> Array[0] >> Array[1] >> Array[2] >> Array[3] >> Array[4]) {
        if(Array[0]==0 && Array[1]==0 && Array[2]==0 && Array[3]==0 && Array[4]==0)
            break;
        sort(Array,Array+5);
        bool capalbe = 0;
        do {
            if(dfs(1,Array[0])) capalbe = 1;
        }while(next_permutation(Array,Array+5));
        if(capalbe) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}