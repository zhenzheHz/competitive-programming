// Author : Zhenzhe
// Time : 2024 / 10 / 16
// Problem : https://zerojudge.tw/ShowProblem?problemid=c121
#include <bits/stdc++.h>
using namespace std;
using Integar = vector<int>;
Integar operator+(Integar &a, Integar &b) {
    Integar A(a.rbegin(),a.rend()), B(b.rbegin(),b.rend()), C;
    if(A.size() < B.size()) swap(A,B);
    for(int i=0;i<A.size();i++) {
        if(i < B.size()) C.push_back(A[i] + B[i]);
        else C.push_back(A[i]);
    }
    C.push_back(0);
    for(int i=0;i<C.size()-1;i++) {
        if(C[i] > 9) C[i+1] += C[i]/10, C[i] %= 10;
    }
    if(C.back() == 0) C.pop_back();
    reverse(C.begin(),C.end());
    return C;
}
void operator<<(ostream &o, Integar &num) {
    for(int i=0;i<num.size();i++) {
        o << num[i];
    }
}

unordered_map<int,Integar> memo;
Integar dfs(int n) {
    if(memo.find(n) != memo.end()) return memo[n];
    Integar A = dfs(n-1), B = dfs(n-2);
    return memo[n] = A + B;
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int test = 1;
    memo[0] = {0};
    memo[1] = {1};
    while(cin >> test) {
        Integar ans = dfs(test);
        cout << "The Fibonacci number for " << test << " is ";
        cout << ans;
        cout << '\n';
    }
}