// Author : Zhenzhe
// Time : 2024 / 11 / 13
// Problem : https://zerojudge.tw/ShowProblem?problemid=c117
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
pair<int,int> dir[] = {{2,1},{2,-1},{1,2},{1,-2}};
pair<int,int> conv(string s) {
    char a = s[0];
    int b = s[1] - '0';
    return {a-'a',b-1};
}
void solve(string a,string b) {
    int dis[8][8];
    memset(dis,0,sizeof(dis));
    pair<int,int> start = conv(a),end = conv(b);
    queue<pair<int,int>> bfs;
    bfs.push(start);
    while(!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();
        for(int k=0;k<4;k++) {
            int tx = cur.first + 
        }
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    while(cin >> a >> b) {
        solve(a,b);
    }
}