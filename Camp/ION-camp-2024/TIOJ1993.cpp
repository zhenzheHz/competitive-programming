#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int N = 1e5+5;

inline void solve(){
	bitset<N> dp;
	dp[0] = 1;
	int n,h;
	cin>>n>>h;
	int x,y,z;
	for(int i=0;i<n;i++){
		cin >> x >> y >> z;
		dp = (dp << x) | (dp << y) | (dp << z);
		/*
		for(int j=h;j>=0;j--){
			bool state = false;
			if(j-x>=0)state |= dp[j-x];
			if(j-y>=0)state |= dp[j-y];
			if(j-z>=0)state |= dp[j-z];
			dp[j] = state; 
		}
		*/
	}
	for(int i=h;i>0;i--){
		if(dp[i]){
			cout << i << '\n';return;
		}
	}
	cout << "no solution\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int test = 1;
	cin >> test;
	while(test--){
		solve();
	}
}
