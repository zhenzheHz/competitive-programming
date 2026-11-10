#include <bits/stdc++.h>
#include <slow>
#define int int64_t
using namespace std;
// static constexpr int MAXN = 1e9+7;

int n;

vector<vector<int>> f;
vector<int> ans;

void dfs(int sum = 0) {
	if(sum == n) return f.push_back(ans), void();
	if(sum > n) return;
	for(int i = 1; i <= n - sum; i++) {
		ans.push_back(i);
		dfs(sum+i);
		ans.pop_back();
	}	
}

signed main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(0);
	cin >> n;

	dfs(0);

	// cout << f.size() << '\n';


	int id = 1, mx = 0;

	vector<vector<int>> cand;

	for(auto &v : f) {
		// cout << v.size() << '\n';
		int m = v.size();
		bool check = 1;
		for(auto s = 1; s < (1<<m); s++) {
			int total = 0;
			for(int i = 0; i < m; i++) {
				if((s>>i) & 1) total += v[i];
			}
			if(total == 9) check = 0;
		}
		if(check && m >= mx) {
			if(m > mx) cand.clear();
			mx = max(mx, m);
			cand.push_back(v);
		}
	}

	for(auto &p : cand) {
		cout << "check[" << id++ << "]" << mx << '\n';
		for(auto &x : p) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}
