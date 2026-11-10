#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n);
	for(int &i : arr)cin>>i;
	int l=0,r=0;
	unordered_map<int,int> mp;
	int ans = 0;
	while(r<n){
		if(mp[arr[r]] == 0){
			mp[arr[r++]]++;
		}else{
			mp[arr[l++]]--;
		}
		ans = max(ans,r-l+1);
	}
	cout << ans;
}
