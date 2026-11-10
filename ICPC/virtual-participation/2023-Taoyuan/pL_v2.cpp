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
		int tmp = n % 10, ans = (n-11)/2 + 1;
		if(tmp == 1) {
			ans = max(ans, (n-1) / 10 * 3 + 1);
		}	
		else if(tmp == 3) {
			ans = max(ans, (n-3) / 10 * 2 + 3);
		}
		else if(tmp == 5 || tmp == 7) {
			ans = max(ans, (n-tmp) / 10 + tmp);
		}
		else {
			ans = max(ans, (n-tmp) / 10 + 8);
		}
		return cout << ans%MOD << '\n', 0;
	}
	else {
		return cout << n * inv(2) % MOD, 0;
	}
}

