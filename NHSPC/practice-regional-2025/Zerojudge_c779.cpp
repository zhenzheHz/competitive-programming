// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=c779
// Tag :  106 北二區 桃竹苗 資訊學科能力複賽 4
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string line,x;
    int max_diff,k,ans = 0;
    vector<int> h;
    getline(cin, line);
    stringstream ss;
    ss << line;
    while(ss >> x) {
        k = stoi(x);
        h.push_back(k);
    }
    cin >> max_diff;
    for(int i = 1; i < (int) h.size(); i++) {
        if(abs(h[i] - h[i-1]) < max_diff) continue;
        ans += (abs(h[i] - h[i-1]) - max_diff);
        if(h[i-1] < h[i]) h[i-1] = h[i] - max_diff;
        else h[i] = h[i-1] - max_diff;
    }
    for(int i = (int) h.size() - 1; i > 0; i--) {
        if(abs(h[i] - h[i-1]) < max_diff) continue;
        ans += (abs(h[i] - h[i-1]) - max_diff);
        if(h[i-1] < h[i]) h[i-1] = h[i] - max_diff;
        else h[i] = h[i-1] - max_diff;
    }
    return cout << ans, 0;
}