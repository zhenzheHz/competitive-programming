// Author : Zhenzhe
// Time : 2024 / 10 / 30
// Problem : https://zerojudge.tw/ShowProblem?problemid=a535
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Manufacturer {
    string name;
    double budget;
    int check, id;
    bool operator<(const Manufacturer &cmp) const {
        if(check == cmp.check) {
            if(budget == cmp.budget) return id < cmp.id;
            else return budget < cmp.budget;
        }else return check > cmp.check;
    }
};
int CASE = 1;
void solve(int n, int p) {
    string need, term, a, b;
    for(int i=0;i<n;i++) getline(cin,need);
    vector<Manufacturer> mafcs(p);
    for(int i=0;i<p;i++) {
        getline(cin,mafcs[i].name);
        getline(cin,term);
        stringstream ss;
        ss << term;
        ss >> a >> b;
        mafcs[i].budget = stod(a);
        mafcs[i].check = stoi(b);
        mafcs[i].id = i;
        for(int j=0;j<mafcs[i].check;j++) getline(cin,need);
    }
    sort(mafcs.begin(), mafcs.end());
    cout << "RFP #" << CASE++ << '\n';
    cout << mafcs[0].name << '\n';
    cout << '\n';
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n, p;
    string line,a,b;
    while(getline(cin,line)) {
        while(!isdigit(line.back())) line.pop_back();
        if(line == "0 0")break;
        stringstream ss;
        ss << line;
        ss >> a >> b;
        n = stoi(a), p = stoi(b);
        solve(n, p);
    }
}