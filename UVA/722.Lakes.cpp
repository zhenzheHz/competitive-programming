// Author : Zhenzhe
// Time : 2024 / 10 / 18
// Problem : https://zerojudge.tw/ShowProblem?problemid=e550
#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    cin.ignore();
    vector<string> grid;
    string row, col;
    while(test--) {
        grid.clear();
        string line, tmp;
        while(getline(cin,line)) {
            int COUNT = 0;
            stringstream ss;
            ss << line;
            bool buffer = false;
            while(ss >> tmp) {
                COUNT += 1;
                if(COUNT == 1) row = tmp;
                if(COUNT == 2) col = tmp, buffer = true;
            }
            if(!buffer) {
                grid.push_back(tmp);
                break;
            }
        }
    }
}