#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string A,B;
    cin >> A >> B;
    if(A.size() < B.size()) swap(A,B);
    int mx = 0;
    for(int l = 0; l < (int) B.size(); l++) {
        for(int r = l+1; r < (int) B.size(); r++) {
            int k = r - l + 1;
            string str = B.substr(l, k);
            if(A.substr(A.size() - k, k) == str) {
                mx = max(mx, (int) str.size());
            }
        }
    }
    cout << A.size() + B.size() - mx;
}