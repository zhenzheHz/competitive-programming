//Problem : Codeforces 888E
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<int> arr;
int ans = 0,n,m;

inline void meet_in_middle(int index,int sum){
	if(index == n+1){
		ans = max(ans,sum);
		return;
	}
	meet_in_middle(index+1,(sum+arr[index])%m);
	meet_in_middle(index+1,sum%m);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	arr.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	meet_in_middle(1,0);
	cout << ans;
}
