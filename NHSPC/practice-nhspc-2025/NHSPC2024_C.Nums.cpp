// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2419
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 105;
int n;
struct Dsu {
    int pa[MAXN], cnt[MAXN], max_cnt, total;
    void init() {
        for(int i = 0; i < MAXN; i++) pa[i] = i, cnt[i] = 1;
        max_cnt = 1;
        total = 0;
    }
    int find(int x) {
        if(x == pa[x]) return x;
        return pa[x] = find(pa[x]);
    }
    void merge(int a,int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        pa[a] = b;
        cnt[b] += cnt[a];
        max_cnt = max(max_cnt, cnt[b]);
    }
    void get() {
        for(int i = 0; i < n; i++) {
            total += (find(i) == i);
        }
    }
};
bool P(string a, string b) {
    if(a.size() < b.size()) swap(a,b);
    reverse(b.begin(), b.end());
    while(b.size() < a.size()) b.push_back('0');
    reverse(b.begin(), b.end());
    string A = "",B = "";
    for(int i = 0; i < (int) a.size(); i++) {
        if(a[i] != b[i]) {
            A.push_back(a[i]);
            B.push_back(b[i]);
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return (A.size() <= 2 && A == B);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    Dsu dsu;
    dsu.init();
    vector<string> nums(n);
    for(auto &str : nums) cin >> str;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(P(nums[i], nums[j])) {
                dsu.merge(i,j);
            }
        }
    }
    dsu.get();
    return cout << dsu.total << ' ' << dsu.max_cnt << '\n', 0;
}