// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=m933
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int p,q,r,m;
struct Node {
    int type, output = -1;
    vector<int> input;
    void gate() {
        // input type
        if(type == -1) return;
        // output type
        if(type == 0) return output = input.front(), void();
        // logical gate
        if(type == 4) return output = !input[0], void();
        int a = input[0], b = input[1];
        if(type == 1) output = a & b;
        if(type == 2) output = a | b;
        if(type == 3) output = a ^ b;
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> p >> q >> r >> m;
    vector<Node> nodes(p+q+r+1);
    vector<int> degree(p+q+r+1, 0), delay(p+q+r+1, 0), g[p+q+r+1];
    for(int i = 1; i <= p; i++) {
        cin >> nodes[i].output;
        nodes[i].type = -1;
    }
    for(int i = p+1; i <= p+q; i++) {
        cin >> nodes[i].type;
    }
    for(int i = p+q+1; i <= p+q+r; i++) {
        nodes[i].type = 0;
    }
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        degree[y]++;
    }
    queue<int> tp;
    for(int i = 1; i <= p+q+r; i++) {
        if(degree[i] == 0) {
            tp.push(i);
        }
    }
    while(!tp.empty()) {
        auto cur = tp.front();
        tp.pop();
        nodes[cur].gate();
        for(auto nxt : g[cur]) {
            delay[nxt] = max(delay[nxt], delay[cur] + 1);
            nodes[nxt].input.push_back(nodes[cur].output);
            if(--degree[nxt] == 0) {
                tp.push({nxt});
            }
        }
    }
    cout << *max_element(delay.begin()+p+q+1,delay.end()) - 1 << '\n';
    for(int i = p+q+1; i <= p+q+r; i++) {
        cout << nodes[i].output << ' ';
    }
    return 0;
}