//Problem : https://cses.fi/problemset/task/1641
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,x;
	cin >> n >> x;
	vector<pair<int,int>> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int l = i-1,r = n;
			int find = -1;
			while(l+1!=r){
				int m = (l+r)>>1;
				if(arr[m].first == x-arr[i].first-arr[j].first){
					find = m;
					break;
				}else if(arr[m].first < x-arr[i].first-arr[j].first){
					l = m;
				}else r = m;
			}
			if(find == i || find == j)continue;
			if(find == -1)continue;
			cout << arr[i].second+1 << ' ' << arr[j].second+1 << ' ' << arr[find].second+1;
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}
