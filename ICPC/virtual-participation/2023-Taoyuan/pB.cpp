#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        int a,b;cin>>a>>b;
        string sa,sb;cin>>sa>>sb;
        int de=9;
        for(int i=0;i<b-1;i++){ de *= 10;de+=9; }
        for(int i=0;i<a;i++) de *= 10;
        string tmp = sa+sb;int na=0,num=0;
        for(int i=sa.size()-1,k = 1;i>=0;i--){
            na+=(sa[i]-'0')*k;
            k*=10;
        }
        for(int i=tmp.size()-1,k=1;i>=0;i--){
            num+=(tmp[i]-'0')*k;
            k*=10;
        }
        //cout<<num<<' '<<na<<'\n';
        num = num-na;
        int mo = gcd(num,de);
        //cout<<num<<' '<<de<<'\n';
        cout<<num/mo<<" "<<de/mo<<'\n';
    }
}

