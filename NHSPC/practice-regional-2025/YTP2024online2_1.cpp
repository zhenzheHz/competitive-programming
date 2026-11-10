// Author : Zhenzhe
// Problem : https://oj.ntucpc.org/problems/442
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = vector<int16_t>;
Integar operator-(const Integar &A, const Integar &B) {
    Integar C;
    int16_t borrow = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        int16_t a = A[i] - borrow;
        int16_t b = (i < (int)B.size()? B[i] : 0);
        if(a < b) a += 10, borrow = 1;
        else borrow = 0;
        C.push_back(a-b);
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string get;
    cin >> get;
    Integar x, minus;
    bool haveOne = false;
    for(int i = 0; i < (int) get.size(); i++) {
        x.push_back(get[i] - '0');
        if(haveOne) minus.push_back(0);
        else if(x[i] == 1) haveOne = true, minus.push_back(2);
        else minus.push_back(x[i]);
    }
    reverse(x.begin(), x.end());
    reverse(minus.begin(), minus.end());
    Integar ans = minus - x;
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}