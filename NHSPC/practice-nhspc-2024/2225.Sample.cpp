// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2020 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2225
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int to_mask(string  a) {
    int mask = 0;
    for(char ch : a) {
        mask |= (1 << (ch - 'a'));
    }
    return mask;
}
int re(string a, string b) {
    int ma = to_mask(a), mb = to_mask(b);
    if((ma & mb) == 0) return 0;
    if((ma & mb) == mb) return 1;
    if((ma & mb) == ma) return 2;
    return 3;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    string x,sample[20];
    cin >> n >> x;
    for(int i=0;i<n;i++) cin>>sample[i];
    array<int,5> ans = {0,0,0,0,0};
    for(int i=0;i<n;i++) {
        int res = re(sample[i], x);
        // cout << res << '\n';
        ans[res]++;
    }
    for(int i=1;i<(1<<x.size())-1;i++) {
        string x1 = "", x2 = "";
        int index = 0, tmp = i;
        for(int j=0;j<x.size();j++) {
            if((i >> j) & 1) x1.push_back(x[j]);
            else x2.push_back(x[j]);
        }
        if(re(x1, x2) == 3) continue;
        // cout << x1 << ' ' << x2 << '\n';
        bool check = 1;
        for(int i=0;i<n;i++) {
            if(re(x1, sample[i]) == 3 || re(x2, sample[i]) == 3) {
                check = 0;
                break;
            }
        }
        if(check) ans[4] += 1;
    }
    assert(ans[4] == 0 || ans[4] == 2);
    for(int i=0;i<5;i++) {
        cout << ans[i] << " \n"[i==4];
    }
}
