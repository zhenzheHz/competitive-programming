#include <bits/stdc++.h>
#define int int64_t
using namespace std;

vector<int> withdraw(const string &str) {
    vector<int> res;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '1') {
            res.push_back(i);
        }
    }
    return res;
}

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string A,B,C;
    cin >> A >> B >> C;
    vector<int> pA,pB,pC;
    pA = withdraw(A);
    pB = withdraw(B);
    pC = withdraw(C);
    
    int ans = 0;
    string X = string(n<<1, '0');
    for(int i = 0; i < n; i++) {
        vector<int> tmp = {pA[i], pB[i], pC[i]};
        sort(tmp.begin(), tmp.end());
        int best = tmp[1];
        X[best] = '1';
        ans += abs(best - pA[i]);
        ans += abs(best - pB[i]);
        ans += abs(best - pC[i]);
    }
    cout << ans << '\n';
    return cout << X << '\n', 0;
}