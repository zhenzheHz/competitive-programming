// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2418
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int cnt[10], inv[10][10];
unordered_map<char,int> id;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    set<int> color_set;
    for(auto color : str) color_set.insert(color);
    vector<char> colors(color_set.begin(), color_set.end());
    for(int i = 0; i < (int) colors.size(); i++) {
        id[colors[i]] = i;
    }
    for(auto color : str) {
        for(int i = 0; i < (int) colors.size(); i++) {
            if(id[color] == i) continue;
            inv[i][id[color]] += cnt[i];
        }
        cnt[id[color]]++;
    }
    sort(colors.begin(), colors.end());
    int best_ans = 1e18, cost = 0;
    do {
        cost = 0;
        for(int i = 0; i < (int) colors.size(); i++) {
            for(int j = i + 1; j < (int) colors.size(); j++) {
                int id_i = id[colors[i]], id_j = id[colors[j]];
                cost += inv[id_j][id_i];
            }
        }
        best_ans = min(best_ans, cost);
    } while(next_permutation(colors.begin(), colors.end()));
    return cout<<best_ans,0;
}