// Author : Zhenzhe
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct line {
    int a,b,c;
    int apply(int x,int y) {
        return a * x + b * y + c;
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    while(cin >> n) {
        int ans = 0;
        vector<line> lines(n);
        for(auto &[a,b,c] : lines) {
            cin >> a >> b >> c;
        }
        cin >> m;
        vector<pair<int,int>> pts(m);
        for(auto &[x,y] : pts) {
            cin >> x >> y;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(auto [x,y] : pts) {
                    if(lines[i].apply(x,y) * lines[j].apply(x,y) <= 0) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}