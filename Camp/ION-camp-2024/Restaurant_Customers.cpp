#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,int>> times;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		times.push_back({l,1});
		times.push_back({r,-1});
	}
	sort(times.begin(),times.end());
	int cur = 0,ans = 0;
	for(auto &t : times){
		cur += t.second;
		ans = max(ans,cur);
	}
	cout << ans;
}
