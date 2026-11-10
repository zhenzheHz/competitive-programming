// Author : Zhenzhe
// Time : 2024 / 11 / 06
// Problem : https://zerojudge.tw/ShowProblem?problemid=d275
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string test,arg;
    getline(cin,test);
    int n = stoi(test);
    while(n--) {
        getline(cin,test);
        stringstream args;
        args << test;
        vector<pair<char,char>> tracks;
        while(args >> arg) {
            tracks.push_back({arg.front(),arg.back()});
        }
        bool loop = true;
        if(tracks.begin()->first == tracks.rbegin()->second)
            loop = false;
        for(int i=0;i<tracks.size()-1;i++) {
            if(tracks[i].second == tracks[i+1].first) {
                loop = false;
                break;
            }
        }
        if(tracks.size() > 1 && loop)cout << "LOOP\n";
        else cout << "NO LOOP\n";
    }
}