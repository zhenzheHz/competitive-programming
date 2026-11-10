// Author : Zhenzhe
// Time : 2024 / 11 / 06
// Porblem : https://zerojudge.tw/ShowProblem?problemid=d663
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<int> primes;
void get_primes() {
    bitset<1005> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i=2;i<1005;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i;j<1005;j+=i)
                is_prime[j] = 0;
        }
    }
}
void div(int x,vector<int> &factors) {
    for(auto prime : primes) {
        if(prime>= x) break;
        if(x % prime == 0) {
            factors.push_back(prime);
        }
    }
}
int solve(int S,int T) {
    queue<pair<int,int>> bfs;
    vector<bool> vis(1005,false);
    bfs.push({S,0});
    vis[S] = 1;
    while(!bfs.empty()) {
        auto [cur, step] = bfs.front();
        vector<int> fcs;
        div(cur,fcs);
        for(auto pfc : fcs) {
            int nxt = cur + pfc;
            if(vis[nxt] || nxt > T) continue;
            if(nxt == T) return step + 1;
            bfs.push({nxt,step+1});
            vis[nxt] = 1;
        }
    }
    return -1;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    get_primes();
    int S,T;
    int CASE = 1;
    while(cin >> S >> T) {
        if(S == 0 && T == 0) break;
        if(S > T) {
            cout << "Case " << CASE++ << ": " << -1 << '\n';
            continue;
        }else if(S == T) {
            cout << "Case " << CASE++ << ": " << 0 << '\n';
            continue;
        }
        cout << "Case " << CASE++ << ": " << solve(S,T) << '\n';
    }
}