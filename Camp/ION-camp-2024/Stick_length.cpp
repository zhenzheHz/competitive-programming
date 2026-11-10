#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int m = arr[n/2],ans = 0;
	for(int i=0;i<n;i++){
		ans += abs(arr[i] - m);
	}
	if(n&1 == 0){
		m = arr[n/2+1];
		int cur = 0;
		for(int i=0;i<n;i++){
			cur += abs(arr[i]-m);
		}
		ans = max(ans,cur);
	}
	cout << ans;
}
