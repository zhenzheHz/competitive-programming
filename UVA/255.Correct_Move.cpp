// Author : Zhenzhe
// Time : 2024 / 10 / 15
// Problem : https://zerojudge.tw/ShowProblem?problemid=e601
#include <bits/stdc++.h>
#define row first
#define column second
using namespace std;
pair<int,int> crdn(int x) {
    // get coordinate
    return make_pair((int)x/8,x%8);
}
bool is_near(int a,int b) {
    pair<int,int> A = crdn(a), B = crdn(b);
    return abs(A.row-B.row) + abs(A.column-B.column) == 1;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int King, queen, go;
    // string ans = "";
    while(cin >> King >> queen >> go) {
        pair<int,int> now = crdn(queen), after = crdn(go), king = crdn(King);
        if(king.row == now.row && king.column == now.column) {
            cout << "Illegal state\n";
            continue;
        }
        if (now.row != after.row && now.column != after.column) {
            cout << "Illegal move\n";
            continue;
        }
        if(queen == go || King == go) {
            cout << "Illegal move\n";
            continue;
        }
        if(now.row == after.row && now.row == king.row) {
            // q1-k-q2 or q2-k-q1
            if(now.column < king.column && king.column < after.column) {
                cout << "Illegal move\n";
                continue;
            }
            if(now.column > king.column && king.column > after.column) {
                cout << "Illegal move\n";
                continue;
            }
        }
        if(now.column == after.column && now.column == king.column) {
            // q1-k-q2 or q2-k-q1
            if(now.row < king.row && king.row < after.row) {
                cout << "Illegal move\n";
                continue;
            }
            if(now.row > king.row && king.row > after.row) {
                cout << "Illegal move\n";
                continue;
            }
        }
        if(is_near(go,King)) 
            cout << "Move not allowed\n";
        else {
            bool check = false;
            if(King >= 8 && !is_near(King-8,go)) check = true;
            if(King <= 55 && !is_near(King+8,go)) check = true;
            if(king.column != 0 && !is_near(King-1,go)) check = true;
            if(king.column != 7 && !is_near(King+1,go)) check = true;
            cout << (check? "Continue\n" : "Stop\n");
        }
    }
}