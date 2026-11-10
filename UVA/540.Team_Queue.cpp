 // Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=e564
#include <bits/stdc++.h>
using namespace std;
void solve(int &CASE,int t);
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int CASE = 1, t;
    while(cin >> t) {
        if(t == 0) break;
        solve(CASE, t);
    }
}
void solve(int &CASE, int t) {
    cout << "Scenario #" << CASE++;
    map<int,int> team, index;
    vector<vector<int>> Queue;
    for(int group = 1; group <= t; group++) {
        int count; cin >> count;
        for(int i=0; i < count; i++) {
            int member; cin >> member;
            team[member] = group;
        }
    }
    string operation;
    while(cin >> operation) {
        if(operation == "STOP") break;
        if(operation == "ENQUEUE") {
            int member; cin >> member;
            if(index.find(team[member]) == index.end()) {
                Queue.push_back({member});
                index[team[member]] = Queue.size();
            }else {
                Queue[index[team[member]]-1].push_back(member);
            }
            continue;
        }
        if(operation == "DEQUEUE") {
            cout << Queue.front().front() << '\n';
            Queue[0].erase(Queue[0].begin());
            if(Queue[0].empty()) {
                Queue.erase(Queue.begin());
                for(auto it = index.begin(); it != index.end(); it = next(it)) {
                    if(it->second == 1) index.erase(it);
                    else index[it->first] -= 1;
                }
            }
        }
    }
    cout << '\n';
}