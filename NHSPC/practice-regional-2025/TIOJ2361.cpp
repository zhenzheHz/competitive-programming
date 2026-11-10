// Problem : https://tioj.ck.tp.edu.tw/problems/2361
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int t,d;
int next(int x) {
    string s = to_string(x);
    while(s.size() < d) s = '0' + s;
    string gt = s, ls = s;
    sort(gt.rbegin(), gt.rend());
    sort(ls.begin(), ls.end());
    return stoll(gt) - stoll(ls);
}
void solve() {
    string s;
    cin >> s;
    int n = stoll(s), result;
    set<int> dfs = {n};
    for(; ; ) {
        result = next(n);
        if(dfs.find(result) != dfs.end())
            return cout << result << '\n',void();
        dfs.insert(result);
        n = result;
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> t >> d;
    while(t--) solve();
}