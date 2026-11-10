// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=e569
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void inspect(string &str) {
    while(str.back() == '\r' || str.back() == '\n') {
        str.pop_back();
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line, word;
    int index;
    vector<string> lst;
    while(getline(cin, line)) {
        // init
        inspect(line);
        if(line == "0") break;
        word.clear();
        index = 0;
        line.push_back('\n');
        // handle
        for(auto &ch : line) {
            if(isalpha(ch)) word.push_back(ch);
            else if(isdigit(ch)) index *= 10, index += ch - '0';
            else {
                // check word
                if(!word.empty()) {
                    cout << word;
                    lst.push_back(word);
                    word.clear();
                }
                // check number to substitute
                if(index != 0) {
                    int sz = lst.size();
                    cout << lst[sz - index];
                    string tmp = lst[sz-index];
                    lst.erase(lst.end() - index);
                    lst.push_back(tmp);
                    index = 0;
                }
                cout << ch;
            }
        }
    }
    return 0;
}