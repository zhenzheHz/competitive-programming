#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,int>> times(n);
	for(int i=0;i<n;i++){
		cin >> times[i].first >> times[i].second;
	}
	using pii = pair<int,int>;
	sort(times.begin(),times.end(),[](const pii a,const pii b){
		return a.second < b.second;
	});
	int r = times[0].second;
	int ans = 1;
	for(int i=1;i<n;i++){
		if(times[i].first < r)continue;
		else{
			ans += 1;
			r = times[i].second;
		}
	}
	cout << ans;
}
