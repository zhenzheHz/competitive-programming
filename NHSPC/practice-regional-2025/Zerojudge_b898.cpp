// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=b898
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
bool cmp(const string &A, const string &B) {
    return (A.size() == B.size()? A < B : A.size() < B.size());
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    string a,b,c;
    for(int i = 0; i < 5; i++) {
        cin >> a >> b >> c;
        vector<string> t = {a,b,c};
        stable_sort(t.begin(), t.end(), cmp);
        cout << *t.rbegin() << '\n';
    }
    return 0;
}