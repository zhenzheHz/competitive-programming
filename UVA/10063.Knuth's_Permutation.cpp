// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=a469
#include <bits/stdc++.h>
using namespace std;
void dfs(string &original, int index, string current) {
    if(current.length() == original.length())
        return cout << current << '\n',void();
    for(int i=0;i<=current.length();i++) {
        dfs(original, index+1, current.substr(0,i) + original[index] + current.substr(i));
    }
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string order;
    //cin >> order;
    while(cin >> order) {
        dfs(order, 0, "");
    }
}