#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
        if(i != s.size()-1) cout << 'o';
    }
    return 0;
}