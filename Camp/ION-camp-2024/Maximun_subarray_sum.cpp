#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n);
	for(int &i : arr)cin>>i;
	int ans = -1e18,cur = 0;
	for(int i=0;i<n;i++){
		cur = max(arr[i],cur+arr[i]);
		ans = max(ans,cur);
	}
	cout << ans;
}
