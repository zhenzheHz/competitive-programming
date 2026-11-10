// Author : Zhenzhe
// Time : 2024 / 11 / 03
// Problem : https://zerojudge.tw/ShowProblem?problemid=d813
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 5e4+5;
class dsu {
    private:
        int pa[MAXN];
        int set_count;
    public:
        void init(int total) {
            set_count = total;
            for(int i=0;i<MAXN;i++)
                pa[i] = i;
        }
        int find(int x) {
            if(x == pa[x]) return pa[x];
            return pa[x] = find(pa[x]);
        }
        void merge(int a,int b) {
            a = find(a), b = find(b);
            if(a == b) return;
            pa[a] = b;
            set_count--;
        }
        int how_many() {
            return set_count;
        }
};
int CASE = 1;
void solve(int n,int m) {
    dsu religion;
    religion.init(n);
    while(m--) {
        int a,b;
        cin >> a >> b;
        religion.merge(a,b);
    }
    cout << "Case " << CASE++ << ": " << religion.how_many() << '\n';
}
signed main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        solve(n,m);
    }
}