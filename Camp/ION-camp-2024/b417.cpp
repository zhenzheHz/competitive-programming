#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int k;

struct query{
	int l,r,id;
	bool operator<(const query &cmp)const{
		if(l/k == cmp.l/k)return r/k < cmp.r/k;
		return l/k < cmp.l/k;
	}
};

unordered_map<int,int>times,cnt;
// cnt -> 數字出現次數
// times -> 數字出現次數有幾種
// cur -> 最大出現次數
inline void add(int val,int &cur){
	times[cnt[val]] -= 1;
	cnt[val] += 1;
	times[cnt[val]] += 1;
	if(times[cnt[val]] == 1)cur = max(cnt[val],cur);
}

inline void sub(int val,int &cur){
	times[cnt[val]] -= 1;
	cnt[val] -= 1;
	times[cnt[val]] += 1;
	if(cur == cnt[val]+1 && times[cnt[val]+1] == 0)cur = cnt[val];
}

int n,q;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	k = sqrt(n);
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	times[0] = n;
	vector<query> Q(q);
	vector<pair<int,int>> ans(q);
	for(int i=0;i<q;i++){
		int a,b;cin>>a>>b;
		Q[i] = {a,b,i};
	}
	sort(Q.begin(),Q.end());
	int l = 1,r = 0,cur = 0;
	for(auto &qry : Q){
		while(r < qry.r)add(arr[++r],cur);
		while(r > qry.r)sub(arr[r--],cur);
		while(l < qry.l)sub(arr[l++],cur);
		while(l > qry.l)add(arr[--l],cur);
		ans[qry.id] = {cur,times[cur]};
	}
	for(int i=0;i<q;i++){
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
