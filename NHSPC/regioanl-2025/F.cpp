#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1505;
vector<int> dp[MAXN][MAXN];
bool better(const vector<int> &x, const vector<int> &y) {
    if(x.size() == y.size()) {
        for(int i = 0; i < (int) x.size(); i++) {
            if(x[i] != y[i]) return x[i] > y[i];
        }
    }
    return x.size() > y.size();
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string a,b;
    vector<int> A,B;
    getline(cin,a);
    getline(cin,b);
    while(a.back() == '\r' || a.back() == '\n') a.pop_back();
    while(b.back() == '\r' || b.back() == '\n') b.pop_back();
    stringstream s1,s2;
    s1 << a; s2 << b;
    int tmp;
    while(s1 >> tmp) A.push_back(tmp);
    while(s2 >> tmp) B.push_back(tmp);
    int n = A.size(), m = B.size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            vector<int> best;
            if(abs(A[i-1] - B[j-1]) <= 1) {
                vector<int> buff;
                for(auto x : dp[i-1][j-1]) buff.push_back(x);
                buff.push_back(A[i-1]);
                if(better(buff, best)) best = buff;
            }
            if(better(dp[i-1][j], best)) best = dp[i-1][j];
            if(better(dp[i][j-1], best)) best = dp[i][j-1];
            dp[i][j] = best;
        }
    }
    for(auto x : dp[n][m]) cout << x << ' ';
    return 0;
}
