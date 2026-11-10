#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct box {
	int t,s,id;
};

static void solve() {
	int n;
	cin >> n;
	vector<box> f(n);
	int i = 0;
	for(auto &[a,b,c] : f) {
		cin >> a >> b;
		c = ++i;
	}
	stable_sort(f.begin(), f.end(), [&](const auto &A, const auto &B) {
		return A.t * B.s < A.s * B.t;		
	});
	for(auto &[t,s,id] : f) {
		cout << id << ' ';
	}
	cout << '\n';
}

signed main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
}
