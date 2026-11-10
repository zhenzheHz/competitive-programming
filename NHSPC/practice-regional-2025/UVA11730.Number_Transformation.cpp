// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=d663
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 1005;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    bitset<MAXN> is_prime;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < MAXN; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    int S,T,Case = 1;
    while(cin >> S >> T) {
        if(S == 0 && T == 0) break;
        vector<int> dis(MAXN, -1);
        queue<int> q;
        q.push(S);
        dis[S] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur == T) break;
            for(int i = 2; i < cur; i++) {
                if(!is_prime[i] || cur % i != 0 || cur + i >= MAXN) continue;
                if(dis[cur+i] >= 0) continue;
                q.push(cur + i);
                dis[cur + i] = dis[cur] + 1;
            }
        }
        cout << "Case " << Case++ << ": " << dis[T] << '\n';
    }
    return 0;
}