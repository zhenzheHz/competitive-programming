// Problem : https://tioj.ck.tp.edu.tw/problems/2330
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1e5+5, MAXM = 1e3+5;
int n,m;
pair<int,int> station[MAXM];
struct House {
    int x,y,rent,id,dis = LLONG_MAX;
    void init() {
        for(int i=1;i<=m;i++) {
            auto [xp,yp] = station[i];
            dis = min(dis, (x-xp)*(x-xp)+(y-yp)*(y-yp));
        }
    }
    bool operator<(const House &cmp) {
        if(dis == cmp.dis) {
            if(rent == cmp.rent) return id < cmp.id;
            else return rent < cmp.rent;
        }return dis < cmp.dis;
    }
};
House houses[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        House s;
        cin >> s.x >> s.y >> s.rent;
        s.id = i;
        houses[i] = s;
    }
    for(int i=1;i<=m;i++) {
        cin >> station[i].first >> station[i].second;
    }
    for(int i=1;i<=n;i++) houses[i].init();
    sort(houses+1, houses+n+1);
    for(int i=1;i<=n;i++)
        cout << houses[i].id << "\n";
    return 0;
}