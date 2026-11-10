// Problem : https://codeforces.com/problemset/problem/242/C
#include <bits/stdc++.h>
using namespace std;
int sx,sy,tx,ty;
const int dx[] = {-1,0,1}, dy[] = {-1,0,1};
map<pair<int,int>,bool> allowed;
map<pair<int,int>,int> dist;
int main() {
    cin >> sx >> sy >> tx >> ty;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int r,a,b;
        cin >> r >> a >> b;
        if(a > b) swap(a,b);
        for(int j = a; j <= b; j++) {
            allowed[{r,j}] = 1;
        }
    }
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[{sx,sy}] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int x : dx) {
            for(int y : dy) {
                if(x == 0 && y == 0) continue;
                int nx = cur.first + x;
                int ny = cur.second + y;
                if(allowed.count({nx, ny}) && !dist.count({nx, ny})) {
                    dist[{nx,ny}] = dist[cur] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << (dist.find({tx,ty}) == dist.end()? -1 : dist[{tx,ty}]);
    return 0;
}