// Author : zhenzhe
// Pre-compiled : 2026/10/29 Thu 20:47:21

#include<bits/stdc++.h>
# 0 "<stdin>"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "<stdin>"



# 1 "/Users/ysh/lab/Coding/library/slow" 1
# 38 "/Users/ysh/lab/Coding/library/slow"
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}

template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
# 5 "<stdin>" 2

using namespace std;

static constexpr long long mod = 998244353;
long long n;
vector<long long> f, fp;
vector<vector<long long>> dp, cnt;

static long long check(const long long l, const long long r) {
    if(l >= r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    long long ans = check(l+1, r) * fp[cnt[l][r]] % mod;
    for(long long m = l; m < r; m++) {
        long long tmp = check(l+1, m) % mod;
        tmp = (tmp * fp[cnt[l][m]]) % mod;
        tmp = (tmp * check(m+1, r)) % mod;
        if(f[l] < f[m+1]) ans = (ans + tmp) % mod;
    }
    return dp[l][r] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f.resize(n);
    fp.resize(n+1);
    for(auto &x : f) cin >> x;
    dp.resize(n, vector<long long> (n,-1));
    cnt.resize(n, vector<long long> (n, 0));
    for(long long i = 0; i < n; i++) dp[i][i] = 1, cnt[i][i] = 0;
    fp[0] = 1;
    for(long long i = 1; i < n; i++) {
        fp[i] = (fp[i-1] * 2) % mod;
        for(long long j = i+1; j < n; j++) {
            cnt[i][j] = cnt[i][j-1] + (f[i] < f[j]);
        }
    }
    fp[n] = (fp[n-1] * 2) % mod;


    cout << check(1,n-1);
}

