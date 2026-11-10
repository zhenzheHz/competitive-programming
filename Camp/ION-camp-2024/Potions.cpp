//Problem : https://codeforces.com/problemset/problem/1526/C2
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr(n+1);
	int ans = 0,cur = 0;
	multiset<int> ms;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(cur + arr[i] >= 0){
			cur += arr[i];
			ms.insert(arr[i]);
			ans += 1;
		}else if(!ms.empty() && cur - *ms.begin() + arr[i] > cur){
			int tmp = *ms.begin();
			ms.erase(ms.begin());
			ms.insert(arr[i]);
			cur += arr[i]-tmp;
		}
	}
	cout << ans;
}
