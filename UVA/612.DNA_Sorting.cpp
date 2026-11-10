// Author : Zhenzhe
// Time : 2024 / 10 / 17
// Problem : https://zerojudge.tw/ShowProblem?problemid=e544
#include <bits/stdc++.h>
using namespace std;
struct DNA {
    string sequence;
    // vector<int> deal;
    int inverse = 0, rk;
    bool operator<(const DNA &cmp) const {
        if(inverse == cmp.inverse) 
            return rk < cmp.rk;
        return inverse < cmp.inverse;
    }
};
void solve();
int INVERSE(string sq,int l,int r);
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
}
int INVERSE(string sq, int l,int r) {
    if(r - l < 1) return 0;
    int m = (l+r)>>1, count = 0;
    string left(sq.begin()+l,sq.begin()+m+1);
    sort(left.begin(),left.end());
    for(int i=m+1;i<=r;i++) {
        auto found = upper_bound(left.begin(),left.end(),sq[i]);
        int index = found - left.begin();
        if(index < 0 || index >= left.size()) continue;
        count += left.size() - index;
    }
    return INVERSE(sq,l,m) + INVERSE(sq,m+1,r) + count;
}
void solve() {
    int length, n;
    cin >> length >> n;
    vector<DNA> data(n);
    for(int i=0;i<n;i++) {
        cin >> data[i].sequence;
        data[i].inverse = INVERSE(data[i].sequence,0,length-1);
        data[i].rk = i;
    }
    sort(data.begin(),data.end());
    for(int i=0;i<n;i++) {
        cout << data[i].sequence << '\n';
    }
    cout << '\n';
}