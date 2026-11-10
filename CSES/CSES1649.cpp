// Problem : https://cses.fi/problemset/task/1649
// Tag : 分塊
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    // divide
    const int block_size = sqrt(n);
    vector<int> block_id(n), ans(n/block_size + 1, (int)1e18);
    for(int i=0;i<n;i++) {
        block_id[i] = i / block_size;
        ans[i/block_size] = min(arr[i],ans[i/block_size]);
    }
    while(q--) {
        int op,a,b;
        cin >> op >> a >> b;
        if(op == 1) {
            a--;
            arr[a] = b;
            ans[block_id[a]] = 1e18;
            int k = block_id[a];
            for(int i=k*block_size;block_id[i]==block_id[a];i++) {
                ans[block_id[a]] = min(ans[block_id[a]],arr[i]);
            }
        }else {
            a--, b--;
            int anss = 1e18;
            if(block_id[a] == block_id[b]) {
                for(int i=a;i<=b;i++) {
                    anss = min(arr[i],anss);
                }
            } else {
                for(int i=a;block_id[i]==block_id[a];i++) {
                    anss = min(arr[i],anss);
                }
                for(int i=b;block_id[i]==block_id[b];i--) {
                    anss = min(arr[i],anss);
                }
                for(int i=block_id[a]+1;i<block_id[b];i++) {
                    anss = min(anss,ans[i]);
                }
            }
            cout << anss << '\n';
        }
    }
}