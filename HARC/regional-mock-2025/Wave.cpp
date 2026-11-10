// Author : Zhenzhe
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void inspect(string &x) {
    while(x.back() == '\r' || x.back() == '\n') x.pop_back();
}
void input(vector<bool> &wave) {
    string line1,line2,line3;
    getline(cin,line1);
    getline(cin,line2);
    getline(cin,line3);
    inspect(line1);
    inspect(line2);
    inspect(line3);
    for(int i = 0; i < (int) line1.size(); i++) {
        bool bit;
        if(line2[i] == '*') {
            if(i >= 1 && line1[i-1] == '*') bit = 0;
            else if(i >= 1 && line3[i-1] == '*') bit = 1;
        }
        else {
            bit = (line1[i] == '*');
        }
        wave.push_back(bit);
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    vector<bool> D,C,Q,correct;
    input(D);
    input(C);
    input(Q);
    bool status, prev;
    for(int i = 0; i < (int)C.size(); i++) {
        prev = (C[i]? D[i] : prev);
        correct.push_back(prev);
    }
    vector<int> ans;
    for(int i = 0; i < (int) Q.size(); i++) {
        if(Q[i] != correct[i]) {
            ans.push_back(i+1);
        }
    }
    if(ans.size() == 0) return cout<<"PASS\n",0;
    for(int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << ",\n"[i+1==ans.size()];
    }
}

/*
   *****   ***       
   *   *   * *       
****   ****** *******
    ***  ****  ****
    * *  *  *  *  *
***** ****  ****  ***
    ****** *****
    *    * *   *
*****    ***   ******
*/