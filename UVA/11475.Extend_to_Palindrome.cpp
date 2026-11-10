// Author : Zhenzhe
// Time : 2024 / 11 / 10
// Problem : https://zerojudge.tw/ShowProblem?problemid=e595
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string str;
    while(cin >> str) {
        string rev = str;
        reverse(rev.begin(),rev.end());
        if(str == rev) {
            cout << str << '\n';
            continue;
        }
        int farest = 0, r = 0, center = 0, ext[(int) 5e5+5];
        memset(ext,0,sizeof(ext));
        string conv = "#";
        for(int i=0;i<str.size();i++) {
            conv.push_back(str[i]);
            conv.push_back('#');
        }
        for(int i=0;i<conv.size();i++) {
            if(i <= r) ext[i] = min(r - i, ext[2 * center - i]);
            while(conv[i - ext[i] - 1] == conv[i + ext[i] + 1]) ext[i] += 1;
            if(i + ext[i] > r) {
                r = i + ext[i];
                center = i;
            }
        }
        int k = ext[center];
        string repeat = str.substr(0,str.size() - k);
        reverse(repeat.begin(),repeat.end());
        cout << str << repeat << '\n';
    }
}