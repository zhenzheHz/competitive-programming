#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n;
char g[3005][3005], tmp[3005][3005];
void rotate(int k) {
    for(int i=k;i<=n-k+1;i++) {
        for(int j=k;j<=n-k+1;j++) {
            g[j][n-i+1] = tmp[i][j];
        }
    }
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        string s;
        cin >> s;
        while(s.back() == '\r' || s.back() == '\n') s.pop_back();
        for(int j = 0; j < (int)s.size() ; j++) {
            g[i][j+1] = s[j];
        }
    }
    for(int i=1;i<=n/2;i++) {
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) tmp[i][j] = g[i][j];
        rotate(i);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}