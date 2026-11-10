// Author : Zhenzhe
// Time : 2024 / 10 / 15
// Problem : https://zerojudge.tw/ShowProblem?problemid=e569
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line;
    vector<string> List; 
    while(getline(cin,line)) {
        if(line == "0") break;
        while(line.back() == '\r') line.pop_back();
        line.push_back('\n');
        string word = "";
        int64_t number = 0;
        for(char ch : line) {
            if(isalpha(ch)) 
                word.push_back(ch);
            else if(isdigit(ch)) 
                number *= 10, number += (ch-'0');
            else {
                if(word != "") {
                    cout << word;
                    List.push_back(word);
                    word = "";
                }
                else if(number != 0) {
                    cout << List[List.size()-number];
                    string tmp = List[List.size()-number];
                    List.erase(List.end()-number);
                    List.push_back(tmp);
                    number = 0;
                }
                cout << ch;
            }
        }
        // cout << '\n';
    }
}