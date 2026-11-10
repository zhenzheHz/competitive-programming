#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
	int n,m;
	cin>>n>>m;
	multiset<int> ms;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		ms.insert(x);
	}
	while(m--){
		int p;cin>>p;
		auto it = ms.upper_bound(p);
		if(it == ms.begin()){
			cout << -1 << '\n';
		}else{
			cout << *prev(it) << '\n';
			ms.erase(prev(it));
		}
	}
}
