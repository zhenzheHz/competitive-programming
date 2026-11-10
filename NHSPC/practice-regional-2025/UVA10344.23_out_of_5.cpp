// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=d762
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool dfs(vector<int> &box, int sum, int idx) {
    if(idx == 5) return sum == 23;
    if(dfs(box, sum+box[idx], idx+1)) return 1;
    if(dfs(box, sum-box[idx], idx+1)) return 1;
    if(dfs(box, sum*box[idx], idx+1)) return 1;
    return 0;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e) {
        if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0) break;
        vector<int> arr = {a,b,c,d,e};
        sort(arr.begin(), arr.end());
        bool valid = 0;
        do {
            if(dfs(arr, arr[0], 1)) {
                valid = 1;
                break;
            }
        } while(next_permutation(arr.begin(), arr.end()));
        cout << (valid? "Possible" : "Impossible") << '\n';
    }
    return 0;
}