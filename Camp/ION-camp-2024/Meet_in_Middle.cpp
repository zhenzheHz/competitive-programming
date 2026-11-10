//Problem : Codeforces 888E
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n,m;
vector<int> arr;
set<int> pref;

inline void brute_front(int index,int sum){
	if(index == n/2+1){
		pref.insert(sum);
	}else{
		brute_front(index+1,(sum+arr[index])%m);
		brute_front(index+1,sum);
	}
}

int ans = 0;

inline void brute_back(int index,int sum){
	if(index == n+1){
		auto it = pref.lower_bound(m - sum);
		if(it == pref.begin())return;
		ans = max(ans,sum + (*prev(it)));
	}else{
		brute_back(index+1,(sum+arr[index])%m);
		brute_back(index+1,sum);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	arr.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}

	brute_front(1,0);// 1 -> n/2
	brute_back(n/2+1,0);// n/2+1 -> n

	cout << ans;
}
