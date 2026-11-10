// Author : ysh
// Pre-compiled : 2026/10/22 Thu 15:23:46

#include<bits/stdc++.h>
# 0 "<stdin>"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "<stdin>"



using namespace std;
# 1 "/Users/ysh/lab/Coding/library/slow" 1
# 38 "/Users/ysh/lab/Coding/library/slow"
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}

template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
# 6 "<stdin>" 2


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

 int64_t n;cin>>n;

 map<pair<int64_t, int64_t>, int64_t>m;

 int64_t a, b;cin>>a;
 map<pair<int64_t, int64_t>, int64_t>l;
 for(int64_t _ = 0;_<a;_++) {
  int64_t a, b, c;cin>>a>>b>>c;
  l.insert({{a, b}, c});
 }

 vector<int64_t>ans(n);
 cin>>b;
 for(int64_t _ = 0;_<b;_++) {
  int64_t a, b, c;cin>>a>>b>>c;
  auto found = l.find({b, a});
  if(found == l.end()) continue;
  ans.at(b - 1) += found -> second * c;
  ans.at(b - 1) %= 1006903069;
 }

 int64_t aans = 0;
 for(auto &i : ans) aans += i, aans %= 1006903069;

 cout<<(aans);
 return 0;
}
/*
// Author : ysh
// 2026/10/22 Thu 15:09:52
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 1006903069
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;cin>>n;

	map<pair<int, int>, int>m;

	int a, b;cin>>a;
	map<pair<int, int>, int>l;
	re(a) {
		int a, b, c;cin>>a>>b>>c;
		l.insert({{a, b}, c});
	}

	vc<int>ans(n);
	cin>>b;
	re(b) {
		int a, b, c;cin>>a>>b>>c;
		auto found = l.find({b, a});
		if(found == l.end()) continue;
		ans.at(b - 1) += found -> second * c;
		ans.at(b - 1) %= R;
	}

	int aans = 0;
	repo(&i, ans) aans += i, aans %= R;

	out(aans);
	return 0;
}
*/

