// Author : zhenzhe
// 2026/10/15 Thu 15:06:28
#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifdef LOCAL
// #include <fast>
#include <slow>
#else
#define debug(x...)
#endif
#define int int64_t
using namespace std;
// using namespace __gnu_pbds;
// #define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int64_t)(x).size())
template <class T> bool chmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool chmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
// static constexpr int INF = 4e18;
// static constexpr int MOD = 1e9 + 7;
// static constexpr int MOD = 998244353;
// static constexpr int MAXN = 2e5 + 5;

void solve() {
    int n;
	cin >> n;
	vector<pair<int,int>> f(n);
	for(int i = 0; i < n; i++) {
		cin >> f[i].second;
	}
	for(int i = 0; i < n; i++) {
		cin >> f[i].first;
	}
	multiset<pair<int,int>> ms;
	for(int i = 0; i < n; i++) {
		ms.insert(f[i]);
	}

	debug(ms);

	while(!ms.empty()) {
		auto ans = ms.begin()->second;
		ms.erase(ms.begin());
		cout << ans << ' ';
	}	

	return cout<<'\n', void();
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
