// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=b839
// Tag :  104 北二區 桃竹苗基 資訊學科能力 複賽 3
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
template<typename... T> 
void debug(T&&... args) {((cout << args << ' '), ...); cout << '\n';}
struct Dsu {
    int pa[55], cnt[55];
    int max_com = 1;
    void init() {
        for(int i = 0; i < 55; i++) pa[i] = i;
        for(int i = 0; i < 55; i++) cnt[i] = 1;
        max_com = 1;
    }
    int find(int x) {
        return (pa[x] == x? x : pa[x] = find(pa[x]));
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        pa[a] = b;
        cnt[b] += cnt[a];
        max_com = max(max_com, cnt[b]);
    }
};
int LCS(string A, string B) {
    int dp[A.size() + 1][B.size() + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= (int) A.size(); i++) {
        for(int j = 1; j <= (int) B.size(); j++) {
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[A.size()][B.size()];
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while(n--) {
        Dsu dsu;
        dsu.init();
        int k;
        cin >> k;
        vector<string> names(k);
        for(int i = 0; i < k; i++) {
            string name;
            cin >> name;
            names[i] = name;
        }
        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < k; j++) {
                int thr = min(names[i].size(), names[j].size());
                thr = (thr + 1) / 2.0;
                if(LCS(names[i],names[j]) >= thr) {
                    dsu.merge(i,j);
                    // debug("i =",i,"j =",j,"LCS =",LCS(names[i],names[j]));
                    // debug("thr :", thr);
                }
            }
        }
        cout << dsu.max_com << '\n';
    }
    return 0;
}