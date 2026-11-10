
#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main() {
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> pa(n + 1, 0), mn;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        pa[i] = pa[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
          
    }

    for(int l = 1;l <= n;l++) {
        for(int r = l;r <= n;r++) {
            
        }
    }
    return 0;
}