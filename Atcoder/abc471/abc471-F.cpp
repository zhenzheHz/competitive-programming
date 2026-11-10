#include <bits/stdc++.h>
#define int int64_t
#define debug(x) cerr << #x << " = " << x << "\n"
using namespace std;
struct Int {
    size_t len;
    int num;
    string s;
    bool operator<(const Int &cmp) const {
        if(len == cmp.len) return num < cmp.num;
        return len < cmp.len;
    }
};
bool better(const string &A, const string &B) {
    if(A.size() == B.size()) return A > B;
    return A.size() > B.size();
}
string trim(string s) {
    int z = 0;
    while (z < s.size() && s[z] == '0') z++;
    if (z == s.size()) return "0";
    return s.substr(z);
}
string build(vector<Int> vec) {
    sort(vec.begin(), vec.end(), [](const Int &a, const Int &b) {
        return a.s + b.s > b.s + a.s;
    });
    string res = "";
    for (auto &x : vec) res += x.s;
    return trim(res);
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    vector<Int> cand(n);
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        cand[i] = {str.size(), stoll(str), str};
    }
    sort(cand.rbegin(), cand.rend());
    vector<Int> c1(cand.begin(), cand.begin() + k);
    string ans = build(c1);
    int max_idx = k - 1;
    for (int i = k; i < n; i++) {
        if (cand[i].num > cand[max_idx].num) {
            max_idx = i;
        }
    }
    vector<Int> c2(cand.begin(), cand.begin() + k - 1);
    c2.push_back(cand[max_idx]);
    string cand2 = build(c2);
    if (better(cand2, ans)) ans = cand2;
    return cout << ans << "\n", 0;
}