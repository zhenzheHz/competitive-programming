// Author : Zhenzhe
// Time : 2024 / 10 / 29
// Problem : https://zerojudge.tw/ShowProblem?problemid=e576
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve();
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 0;
    cin >> test;
    while(test--) {
        solve();
    }
}
void solve() {
    int m,N = 0,a,b;
    cin >> m;
    pair<int,int> target = {0,m};
    vector<pair<int,int>> segment,ans;
    while(cin >> a >> b) {
        if(a==0 && b==0) break;
        N += 1;
        segment.push_back(make_pair(a,b));
    }
    sort(segment.begin(),segment.end());
    int index = 0;
    while(target.first < m) {
        int max_r = 0, max_index = -1;
        bool found = false;
        while(index < N) {
            if(segment[index].first <= target.first) {
                found = true;
                if(segment[index].second > max_r) {
                    max_r = segment[index].second;
                    max_index = index;
                }else break;
            }
            index += 1;
        }
        if(!found) break;
        else {
            ans.push_back(segment[max_index]);
            target.first = max_r;
        }
    }
    if(target.first >= target.second) {
        cout << ans.size() << '\n';
        for(auto point : ans) {
            cout << point.first << ' ' << point.second << '\n';
        }
    }else cout << "0\n";
    cout << '\n';
}