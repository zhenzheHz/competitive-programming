#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5;
int S;
int arr[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n;
    S = sqrt(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cin >> q;
    vector<pair<int,int>> buff;
    while(q--) {
        int op,l,r,idx;
        cin >> op;
        if(op == 1) {
            cin >> l >> r;
            l--, r--;
            buff.push_back({l,r});
        }
        else {
            cin >> idx;
            idx--;
            int tmp = arr[idx];
            for(auto [ql,qr] : buff) {
                if(ql <= idx && idx <= qr) {
                    tmp /= 2;
                }
            }
            cout << tmp << '\n';
        }
        if((int)buff.size() >= S) {
            for(auto [ql,qr] : buff) {
                for(int i=ql;i<=qr;i++) {
                    arr[i] /= 2;
                }
            }
            buff.clear();
        }
    }
    return 0;
}