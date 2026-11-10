#include <bits/stdc++.h>
#define int int64_t
using namespace std;

static constexpr int MOD = 1e9+7;

static inline int fp(const int a,int b) {
	if(b == 0) return 1;
	if(b & 1) return a * fp(a,b-1) % MOD;
	int h = fp(a, b>>1);
	return h*h%MOD;
}

inline int inv(int x) {
	return fp(x, MOD-2) % MOD;
}

signed main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	if(n <= 8) {
		cout << n << '\n';
	}
	else if(n & 1) {
		int tmp = n % 10, ans = 0;
		if(n == 11) return cout<<4,0;
		//if(n == 21) return cout<<9,0;
		ans = max({(n-11)/2 + 1, (n-3)/10 * 2 + 3});
		int t = min(tmp, (int)8);
		if(n > 18) ans = max({ans, (n-t)/10 + t, (n-8)/10 + 8});
		// if(tmp == 7) ans = max(ans, (n-7)/10 + 7);
		// if(tmp == 9) ans = max(ans, (n-8)/10 + 8);
		return cout << ans << '\n', 0;
		// return cout << max({(n-11)/2 + 1, (n-3) / 10 * 2 + 3, (n-tmp) / 10 + min(tmp, (int)8)}) % MOD << '\n', 0;
		// if(tmp == 1) {
		// 	ans = max(ans, );
		// }	
		// else if(tmp == 3) {
		// 	ans = max(ans, );
		// }
		// else if(tmp == 5 || tmp == 7) {
		// 	ans = max(ans, );
		// }
		// else {
		// 	ans = max(ans, );
		// }
		// return cout << ans%MOD << '\n', 0;
	}
	else {
		return cout << n * inv(2) % MOD, 0;
	}
}
