// Problem : https://codeforces.com/contest/1146/problem/A
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s) {
        cnt += c == 'a';
    }
    cout << (2*cnt > s.size()? s.size() : cnt*2-1); 
}