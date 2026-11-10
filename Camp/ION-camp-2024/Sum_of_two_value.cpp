#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		int l = i,r = n;
		while(l+1!=r){
			int m = (l+r)>>1;
			if(arr[m].first == x-arr[i].first){
				cout << arr[i].second+1 << ' ' << arr[m].second+1;
				return 0;
			}
			if(arr[m].first < x-arr[i].first)l = m;
			else r = m;
		}
	}
	cout << "IMPOSSIBLE";
}
