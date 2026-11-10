// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2225
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
string X,S;
int to_mask(string &s) {
    int result = 0;
    for(auto ch : s) {
        result |= (1 << (ch - 'a'));
    }
    return result;
}
int relate(string A, string B) {
    int mask_A = to_mask(A), mask_B = to_mask(B);
    int common = mask_A & mask_B;
    if(common == 0) return 0;
    if(common == mask_B) return 1;
    if(common == mask_A) return 2;
    return 3;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cin >> X;
    vector<string> normal(n);
    for(auto &str : normal) cin >> str;
    array<int,5> ans = {0,0,0,0,0};
    for(auto str : normal) {
        ans[relate(str,X)] += 1;
    }
    int k = X.size();
    for(int status = 0; status < (1<<k); status++) {
        string X1 = "", X2 = "";
        for(int i = 0; i < k; i++) {
            if((status >> i) & 1) X1.push_back(X[i]);
            else X2.push_back(X[i]);
        }
        if(relate(X1,X2) == 3) continue;
        bool valid = 1;
        for(auto sample : normal) {
            if(relate(sample,X1) == 3 || relate(sample,X2) == 3) {
                valid = 0;
            }
        }
        if(valid) ans[4]++;
    }
    for(auto x : ans) cout << x << ' ';
    return 0;
}