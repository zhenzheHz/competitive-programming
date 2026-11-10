// Problem : https://atcoder.jp/contests/abc258/tasks/abc258_g
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	static constexpr int N = 3001;
	bitset<N> g[N];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char x;cin>>x;
			g[i][j] = (x=='1');
			//cerr << x;
		}
		//cerr << '\n';
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(g[i][j])ans += (g[i] & g[j]).count();
		}
	}
	cout << ans/3 << '\n';
}
