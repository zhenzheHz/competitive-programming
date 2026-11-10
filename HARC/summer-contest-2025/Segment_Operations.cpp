#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n;
    int arr[n+1];
    set<int> st;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        st.insert(i);
    }
    cin >> q;
    while(q--) {
        int op,l,r,idx;
        cin >> op;
        if(op == 1) {
            cin >> l >> r;
            auto it = st.lower_bound(l);
            while(it != st.end() && *it <= r) {
                arr[*it] /= 2;
                if(arr[*it] == 0) it = st.erase(it);
                else it++;
            }
        }else {
            cin >> idx;
            cout << arr[idx] << '\n';
        }
    }
}