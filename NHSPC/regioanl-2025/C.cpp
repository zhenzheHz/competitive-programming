#include <bits/stdc++.h>
#define int int64_t
using namespace std;
const char base[] = {'A','T','C','G'};
bool check(string &DNA) {
    for(auto &ch : DNA) {
        bool fd = 0;
        for(auto x : base) {
            if(ch == x) fd = 1;
        }
        if(!fd) return 0;
    }
    return 1;
} 
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string A,B;
    cin >> A >> B;
    if(!check(A) || !check(B)) return cout<<-1,0;
    if(A.size() < B.size()) return cout<<-1,0;
    reverse(B.begin(), B.end());
    for(auto &ch : B) {
        if(ch == 'A') ch = 'T';
        else if(ch == 'T') ch = 'A';
        else if(ch == 'C') ch = 'G';
        else if(ch == 'G') ch = 'C';
    }
    vector<int> ans;
    for(int i = 0; i < (int) A.size(); i++) {
        string tmp = A.substr(i,B.size());
        if(tmp == B) ans.push_back(i+1);
    }
    if(ans.empty()) return cout<<-1,0;
    for(auto idx : ans) cout << idx << ' ';
    return 0;
}
