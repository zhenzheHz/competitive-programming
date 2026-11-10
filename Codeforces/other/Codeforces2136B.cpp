// Problem : https://codeforces.com/contest/2136/problem/B
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
void solve() {
    int n,k;string s;
    cin >> n >> k >> s;
    int cur_id = 1;
    int ans[n];
    for(int i=0;i<n;i++) {
        ans[i] = (s[i] == '1'? cur_id++ : 0);
    }
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            ans[i] = cur_id++;
        }
    }
    set<int> st;
    for(int i=0;i<k;i++) st.insert(ans[i]);
    for(int i=0;i<k;i++) {
        if(s[i] == '1' && st.upper_bound(ans[i]) == st.end()) {
            return cout << "No\n", void();
        }
    }
    for(int i=1;i+k-1<n;i++) {
        st.erase(ans[i-1]);
        st.insert(ans[i+k-1]);
        if(s[i+k-1] == '1' && st.upper_bound(ans[i+k-1]) == st.end()) {
            return cout << "No\n", void();
        }
    }
    cout << "Yes\n";
    for(int i=0;i<n;i++) {
        cout << ans[i] << " \n"[i==n-1];
    }
    return;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) solve();
}