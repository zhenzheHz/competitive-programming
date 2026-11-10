// Author : Zhenzhe
// Time : 2024 / 11 / 01
// Problem : https://zerojudge.tw/ShowProblem?problemid=e507
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    while(cin >> a >> b) {
        int alphabet[26][2];
        memset(alphabet,0,sizeof(alphabet));
        for(char c : a) alphabet[c-'a'][0] += 1;
        for(char c : b) alphabet[c-'a'][1] += 1;
        string answer = "";
        for(int i=0;i<26;i++) {
            int times = min(alphabet[i][0],alphabet[i][1]);
            char c = 'a' + i;
            for(int i=0;i<times;i++) 
                answer.push_back(c);
        }
        sort(answer.begin(),answer.end());
        cout << answer << '\n';
    }  
}